<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/AssertionBacktrace.hh";

class Assertion {
    private bool $not = false;

    public function __construct(private (function(AssertionLocation) : void) $successHandler, private (function(AssertionLocation) : void) $failureHandler) {}

    private function backtrace() : AssertionBacktrace {
        $trace = \debug_backtrace();

        $assertionDepth = 2;
        $testDepth = 3;

        return new AssertionBacktrace($trace[$assertionDepth]["file"], $trace[$assertionDepth]["line"]);
    }

    protected function assert(bool $evaluation) : void {
        $backtrace = $this->backtrace(); 

        if($this->not ? !$evaluation : $evaluation) {
            call_user_func($this->successHandler, $backtrace);
        } else {
            call_user_func($this->failureHandler, $backtrace);
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
require_once dirname(__FILE__) . "/MapAssertion.hh";
require_once dirname(__FILE__) . "/VectorAssertion.hh";
