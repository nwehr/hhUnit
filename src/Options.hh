<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hhUnit;

interface IOptions {
    public function directoryPaths() : Vector<string>;
    public function namespaceNames() : Vector<string>;
    public function listTests() : bool;
    public function showHelp() : bool;
}

class Options implements IOptions {
    protected static ?Options $instance = null;

    protected function __construct(protected darray<string, mixed> $opt) {}

    public static function instance() : Options {
        if(!self::$instance) {
            self::$instance = new self(\getopt("hld:n:i:"));
        }

        return self::$instance;
    }

    public function directoryPaths() : Vector<string> {
        if (!\array_key_exists("d", $this->opt)) {
            return Vector{};
        }

        if(\is_array($this->opt["d"])) {
            return $this->opt["d"] |> new Vector($$);
        } else {
            return Vector{(string)$this->opt["d"]};
        }
    }

    public function namespaceNames() : Vector<string> {
        if(!\array_key_exists("n", $this->opt)) {
            return Vector{};
        } 

        if(\is_array($this->opt["n"])) {
            return new Vector($this->opt["n"]);
        } 

        return Vector{(string)$this->opt["n"]};
    }

    public function includePaths() : Vector<string> {
        if (\array_key_exists("i", $this->opt)) {
            return \explode(":", (string)$this->opt["i"]) |> new Vector($$);
        }

        return Vector{};
    }

    public function listTests() : bool {
        return \array_key_exists("l", $this->opt);
    }

    public function showHelp() : bool {
        return \array_key_exists("h", $this->opt);
    }
}