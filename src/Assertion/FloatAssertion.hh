<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class FloatAssertion extends Assertion {
    public function __construct(private float $float, Signal $success, Signal $failure) {
        parent::__construct($success, $failure);
    }

    public function equalToFloat(float $float) : void {
        $this->assert($this->float == $float);
    }
}
