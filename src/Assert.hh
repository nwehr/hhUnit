<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Signal.hh";
require_once dirname(__FILE__) . "/Assertion/Assertion.hh";

class Assert {
    public Signal $success;
    public Signal $failure;

    public function __construct() {
        $this->success = new Signal();
        $this->failure = new Signal();
    }

    public function bool(bool $bool) : BoolAssertion {
        return new BoolAssertion($bool, $this->success, $this->failure);
    }

    public function int(int $int) : IntAssertion {
        return new IntAssertion($int, $this->success, $this->failure);
    }

    public function float(float $float) : FloatAssertion {
        return new FloatAssertion($float, $this->success, $this->failure);
    }

    public function string(string $string) : StringAssertion {
        return new StringAssertion($string, $this->success, $this->failure);
    }

    public function array(array $array) : ArrayAssertion {
        return new ArrayAssertion($array, $this->success, $this->failure);
    }
}
