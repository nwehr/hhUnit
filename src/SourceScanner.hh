<?hh
namespace NDUnit;

class SourceScanner {
    public Vector<string> $sources = Vector{};

    private function _scan(string $path) {
        if(is_dir($path)) {
            $dir = dir($path);

            while(false !== ($entry = $dir->read())) {
                if($entry == "." || $entry == "..") {
                    continue;
                }

                $fullEntry = $dir->path . "/" . $entry;

                if(!is_dir($fullEntry)) {
                    $this->sources->add($fullEntry);
                } else {
                    $this->_scan($fullEntry);
                }
            }
        } else {
            $this->sources->add($path);
        }
    }

    public function scan(Vector<string> $paths) : SourceScanner {
        foreach($paths as $path) {
            $this->_scan($path);
        }

        return $this;
    }
}
