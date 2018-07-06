<?hh
namespace NDUnit;

class SourceScanner {
    public Vector<string> $sources = Vector{};

    private function isSourceFile(string $path) {
        $info = pathinfo($path);

        if(array_key_exists("extension", $info) && ($info["extension"] == "hh" || $info["extension"] == "php")) {
            return true; 
        } else {
            return false;
        }
    }

    private function _scan(string $path) {
        if(is_dir($path)) {
            $dir = dir($path);

            while(false !== ($entry = $dir->read())) {
                if($entry == "." || $entry == "..") {
                    continue;
                }

                $fullEntry = $dir->path . "/" . $entry;

                if(!is_dir($fullEntry) && $this->isSourceFile($fullEntry)) {
                    $this->sources->add($fullEntry);
                } else {
                    $this->_scan($fullEntry);
                }
            }
        } else {
            if($this->isSourceFile($path)) {
                $this->sources->add($path);
            }
        }
    }

    public function scan(Vector<string> $paths) : SourceScanner {
        foreach($paths as $path) {
            $this->_scan($path);
        }

        return $this;
    }
}
