<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/AssertionResult.hh";
require_once dirname(__FILE__) . "/../Signal.hh";

class Assertion {
    private string $class = "";
    private string $method = "";
    private string $file = "";
    private int $line = 0;

    protected bool $not = false;

    public function __construct(protected Signal $success, protected Signal $failure) {}

    protected function backtrace() {
        $trace = \debug_backtrace();

        $this->file = $trace[2]["file"];
        $this->line = $trace[2]["line"];

        $this->class = $trace[3]["class"];
        $this->method = $trace[3]["function"];
    }

    protected function assert(bool $evaluation) : void {
        $this->backtrace(); 

        if($this->not ? !$evaluation : $evaluation) {
            $this->success->emit(new AssertionResult($this->class, $this->method, $this->file, $this->line));
        } else {
            $this->failure->emit(new AssertionResult($this->class, $this->method, $this->file, $this->line));
        }
    }

    public function not() : Assertion {
        $this->not = true;
        return $this;
    }
}

require_once dirname(__FILE__) . "/BoolAssertion.hh";
require_once dirname(__FILE__) . "/IntAssertion.hh";
require_once dirname(__FILE__) . "/FloatAssertion.hh";
require_once dirname(__FILE__) . "/StringAssertion.hh";
require_once dirname(__FILE__) . "/ArrayAssertion.hh";
