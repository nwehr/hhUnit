<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

class FileSystemScanner {
    public Vector<string> $sourceFiles = Vector{};

    private function isSourceFile(string $path) : bool {
        $pathInfo = new Map(pathinfo($path));

        if($pathInfo->containsKey("extension") && $pathInfo["extension"] == "hh") {
            return true; 
        } else {
            return false;
        }
    }

    private function scanPath(string $path) : void {
        if(is_dir($path)) {
            $directory = dir($path);

            while(($entry = $directory->read())) {
                if($entry == "." || $entry == "..") {
                    continue;
                }

                $this->scanPath($directory->path . "/" . $entry);
            }
        } else if($this->isSourceFile($path)) {
            $this->sourceFiles->add($path);
        }
    }

    public function scanPaths(Vector<string> $paths) : FileSystemScanner {
        foreach($paths as $path) {
            $this->scanPath($path);
        }

        return $this;
    }
}
