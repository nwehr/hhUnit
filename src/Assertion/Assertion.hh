<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/AssertionResult.hh";
require_once dirname(__FILE__) . "/../Signal.hh";

class Assertion {
    private string $file = "";
    private int $line = 0;

    protected bool $not = false;

    public function __construct(protected Signal $success, protected Signal $failure) {}

    protected function backtrace(array $backtrace) {
        $this->file = $backtrace[0]["file"];
        $this->line = $backtrace[0]["line"];
    }

    protected function assert(bool $evaluation) : void {
        if($this->not ? !$evaluation : $evaluation) {
            $this->success->emit(new AssertionResult("", "", $this->file, $this->line));
        } else {
            $this->failure->emit(new AssertionResult("", "", $this->file, $this->line));
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
