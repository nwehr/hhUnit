<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/AssertionLocation.hh";
require_once dirname(__FILE__) . "/../Signal.hh";

class Assertion {
    private bool $not = false;

    public function __construct(private AssertSignals $signals) {

    }

    private function backtrace() : (string, string, string, int) {
        $trace = \debug_backtrace();

        $assertionDepth = 2;
        $testDepth = 3;

        return tuple($trace[$testDepth]["class"]
            , $trace[$testDepth]["function"]
            , $trace[$assertionDepth]["file"]
            , $trace[$assertionDepth]["line"]);
    }

    protected function assert(bool $evaluation) : void {
        list($testSuite, $test, $file, $line) = $this->backtrace(); 

        $location = new AssertionLocation($testSuite, $test, $file, $line);

        if($this->not ? !$evaluation : $evaluation) {
            $this->signals->success()->emit($location);
        } else {
            $this->signals->failure()->emit($location);
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
