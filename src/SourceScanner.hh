<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

class SourceScanner {
    public Vector<string> $sources = Vector{};

    private function isSourceFile(string $path) : bool {
        $info = new Map(pathinfo($path));

        if($info->containsKey("extension") && $info["extension"] == "hh") {
            return true; 
        } else {
            return false;
        }
    }

    private function scan(string $path) : void {
        if(is_dir($path)) {
            $dir = dir($path);

            while(false !== ($entry = $dir->read())) {
                if($entry == "." || $entry == "..") {
                    continue;
                }

                $this->scan($dir->path . "/" . $entry);
            }
        } else if($this->isSourceFile($path)) {
            $this->sources->add($path);
        }
    }

    public function scanPaths(Vector<string> $paths) : SourceScanner {
        foreach($paths as $path) {
            $this->scan($path);
        }

        return $this;
    }
}
