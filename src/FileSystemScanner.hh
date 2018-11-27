<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

interface IFileSystemScanner {
    public function getSourcePaths(Vector<string> $directoryPaths) : Vector<string>;
}

class FileSystemScanner implements IFileSystemScanner {
    protected Vector<string> $sourcePaths = Vector{};
    protected Vector<string> $ignorePaths = Vector{};

    protected function isSourceFile(string $path) : bool {
        $pathInfo = new Map(pathinfo($path));

        if($pathInfo->containsKey("extension") && $pathInfo["extension"] == "hh") {
            return true; 
        } else {
            return false;
        }
    }

    protected function shouldIgnore(string $path) : bool {
        foreach($this->ignorePaths as $ignorePath) {
            $pattern = "/^" . str_replace("/", "\/", $ignorePath) . "/";

            if(preg_match($pattern, $path)) {
                echo "$pattern == $path\n";
                return true; 
            }
        }

        return false;
    }

    protected function scanDirectoryForIgnoreFile(string $path) : void {
        $ignoreFilePath = $path . "/.hunitignore";

        if(file_exists($ignoreFilePath)) {
            $handle = fopen($ignoreFilePath, "r");

            while(($line = fgets($handle)) !== false) {
                $pathToIgnore = realpath(trim($line));

                if($pathToIgnore) {
                    $this->ignorePaths->add($pathToIgnore);
                }
            }

            fclose($handle);
        }
    }

    protected function scanPath(string $path) : void {


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
            $this->sourcePaths->add($path);
        }
    }

    public function getSourcePaths(Vector<string> $directoryPaths) : Vector<string> {
        foreach($directoryPaths as $path) {
            $this->scanPath($path);
        }

        return $this->sourcePaths;
    }
}
