<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Signal.hh";
require_once dirname(__FILE__) . "/Assertion/Assertion.hh";

class Assert implements \IDisposable {
    public Signal $success = new Signal();
    public Signal $failure = new Signal();

    public function __dispose() {
        $this->success->disconnectAll();
        $this->failure->disconnectAll();
    }

    private function reEmitAssertionSignals(Assertion $assertion) : Assertion {
        $assertion->success->connect((AssertionLocation $location) ==> {
            // echo "Assert::handleSuccess()\n";
            $this->success->emit($location);
        });

        $assertion->failure->connect((AssertionLocation $location) ==> {
            $this->failure->emit($location);
        });

        return $assertion;
    }

    public function bool(bool $bool) : BoolAssertion {
        return $this->reEmitAssertionSignals(new BoolAssertion($bool));
    }

    public function int(int $int) : IntAssertion {
        return $this->reEmitAssertionSignals(new IntAssertion($int));
    }

    public function float(float $float) : FloatAssertion {
        return $this->reEmitAssertionSignals(new FloatAssertion($float));
    }

    public function string(string $string) : StringAssertion {
        return $this->reEmitAssertionSignals(new StringAssertion($string));
    }

    public function array(array $array) : ArrayAssertion {
        return $this->reEmitAssertionSignals(new ArrayAssertion($array));
    }
}
