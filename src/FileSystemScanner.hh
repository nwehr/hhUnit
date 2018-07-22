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
    private Vector<string> $ignorePaths = Vector{};

    private function isSourceFile(string $path) : bool {
        $pathInfo = new Map(pathinfo($path));

        if($pathInfo->containsKey("extension") && $pathInfo["extension"] == "hh") {
            return true; 
        } else {
            return false;
        }
    }

    private function shouldIgnore(string $path) : bool {
        foreach($this->ignorePaths as $ignorePath) {
            $pattern = "/^" . str_replace("/", "\/", $ignorePath) . "/";

            if(preg_match($pattern, $path)) {
                return true; 
            }
        }

        return false;
    }

    private function scanDirectoryForIgnoreFile(string $path) : void {
        $ignoreFilePath = $path . "/.hunitignore";

        if(file_exists($ignoreFilePath)) {
            $handle = fopen($ignoreFilePath, "r");

            while(($line = fgets($handle)) !== false) {
                $pathToIgnore = trim($line);
                if(preg_match("/[\/A-z0-9\.]+/", $pathToIgnore)) {
                    $this->ignorePaths->add(realpath($pathToIgnore));
                }
            }

            fclose($handle);
        }
    }

    private function scanPath(string $path) : void {
        if($this->shouldIgnore($path)) {
            return;
        }

        if(is_dir($path)) {
            chdir($path);

            $this->scanDirectoryForIgnoreFile($path);            

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
