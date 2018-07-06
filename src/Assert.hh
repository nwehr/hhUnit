<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/AssertResult.hh";
require_once dirname(__FILE__) . "/Signal.hh";

class Assert {
    private string $file = "";
    private int $line = 0;

    private ?bool $bool;
    private ?int $int;
    private ?float $float;
    private ?string $string;
    private ?array $array;
    
    private bool $not = false;

    public Signal $success;
    public Signal $failure;

    public function __construct(private string $class, private string $method) {
        $this->success = new Signal();
        $this->failure = new Signal();
    }

    private function backtrace(array $backtrace) {
        $this->file = $backtrace[0]["file"];
        $this->line = $backtrace[0]["line"];
    }

    private function success() : void {
        $this->success->emit(new AssertResult($this->class, $this->method, $this->file, $this->line));
    }

    private function failure() : void {
        $this->failure->emit(new AssertResult($this->class, $this->method, $this->file, $this->line));
    }

    private function assert(bool $evaluation) : void {
        if($this->not ? !$evaluation : $evaluation) {
            $this->success();
        } else {
            $this->failure();
        }
    }

    public function not() : Assert {
        $this->not = true;
        return $this;
    }

    public function bool(bool $bool) : Assert {
        $this->bool = $bool;
        return $this;
    }

    public function int(int $int) : Assert {
        $this->int = $int;
        return $this;
    }

    public function float(float $float) : Assert {
        $this->float = $float;
        return $this;
    }

    public function string(string $string) : Assert {
        $this->string = $string;
        return $this;
    }

    public function array(array $array) : Assert {
        $this->array = $array;
        return $this;
    }

    public function equalToBool(bool $bool) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->bool == $bool);

        return $this;
    }

    public function equalToInt(int $int) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->int == $int);

        return $this;
    }

    public function greaterThanInt(int $int) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->int > $int);

        return $this;
    }

    public function greaterThanOrEqualToInt(int $int) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->int >= $int);

        return $this;
    }

    public function lessThanInt(int $int) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->int < $int);

        return $this;
    }

    public function lessThanOrEqualToInt(int $int) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->int <= $int);

        return $this;
    }

    public function equalToFloat(float $float) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->float == $float);

        return $this;
    }

    public function equalToString(string $string) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->string == $string);

        return $this;
    }

    public function equalToArray(array $array) : Assert {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->array == $array);

        return $this;
    }
}
