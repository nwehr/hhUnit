<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hhUnit;

require_once \dirname(__FILE__) . "/AssertionBacktrace.hh";

type SuccessHandlerFn = (function(AssertionBacktrace) : void);
type FailureHandlerFn = (function(AssertionBacktrace, string, string) : void);

class Assertion {
    private bool $not = false;

    public function __construct(private SuccessHandlerFn $successHandler, private FailureHandlerFn $failureHandler) {}

    private function backtrace() : AssertionBacktrace {
        $trace = \debug_backtrace();

        $assertionDepth = 2;
        $testDepth = 3;

        return new AssertionBacktrace($trace[$assertionDepth]["file"], $trace[$assertionDepth]["line"]);
    }

    protected function assert(bool $evaluation, string $expected, string $got) : void {
        $backtrace = $this->backtrace(); 

        if($this->not ? !$evaluation : $evaluation) {
            \call_user_func($this->successHandler, $backtrace);
        } else {
            \call_user_func($this->failureHandler, $backtrace, $expected, $got);
        }
    }

    public function not() : this {
        $this->not = true;
        return $this;
    }
}

require_once \dirname(__FILE__) . "/BoolAssertion.hh";
require_once \dirname(__FILE__) . "/IntAssertion.hh";
require_once \dirname(__FILE__) . "/FloatAssertion.hh";
require_once \dirname(__FILE__) . "/StringAssertion.hh";
require_once \dirname(__FILE__) . "/ArrayAssertion.hh";
require_once \dirname(__FILE__) . "/MapAssertion.hh";
require_once \dirname(__FILE__) . "/VectorAssertion.hh";
