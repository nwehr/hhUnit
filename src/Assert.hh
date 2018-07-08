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
    public AssertSignals $signals = new AssertSignals();

    public function __dispose() {
        $this->signals->success()->disconnectAll();
        $this->signals->failure()->disconnectAll();
    }

    public function bool(bool $bool) : BoolAssertion {
        return new BoolAssertion($bool, $this->signals);
    }

    public function int(int $int) : IntAssertion {
        return new IntAssertion($int, $this->signals); 
    }

    public function float(float $float) : FloatAssertion {
        return new FloatAssertion($float, $this->signals);
    }

    public function string(string $string) : StringAssertion {
        return new StringAssertion($string, $this->signals);
    }

    public function array(array $array) : ArrayAssertion {
        return new ArrayAssertion($array, $this->signals);
    }
}
