<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

interface IOptions {
    public function directoryPaths() : Vector<string>;
    public function namespaceNames() : Vector<string>;
    public function listTests() : bool;
    public function showHelp() : bool;
}

class Options implements IOptions {
    protected static ?Options $instance = null;

    protected function __construct(protected array $opt) {}

    public static function instance() : Options {
        if(!self::$instance) {
            self::$instance = new self(getopt("hld:n:"));
        }

        return self::$instance;
    }

    public function directoryPaths() : Vector<string> {
        if(is_array($this->opt["d"])) {
            return new Vector($this->opt["d"]);
        } else {
            return Vector{$this->opt["d"]};
        }
    }

    public function namespaceNames() : Vector<string> {
        if(!array_key_exists("n", $this->opt)) {
            return Vector{};
        } else {
            if(is_array($this->opt["n"])) {
                return new Vector($this->opt["n"]);
            } else {
                return Vector{$this->opt["n"]};
            }
        }
    }

    public function listTests() : bool {
        return array_key_exists("l", $this->opt);
    }

    public function showHelp() : bool {
        return array_key_exists("h", $this->opt);
    }
}