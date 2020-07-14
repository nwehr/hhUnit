<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hhUnit;

require_once \dirname(__FILE__) . "/Assertion.hh";

class FloatAssertion extends Assertion {
    public function __construct(private float $float, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(float $float) : void {
        $this->assert($this->float == $float, (string)$this->float, (string)$float);
    }

    public function greaterThan(float $float) : void {
        $this->assert($this->float > $float, (string)$this->float, (string)$float);
    }

    public function greaterThanOrEqualTo(float $float) : void {
        $this->assert($this->float >= $float, (string)$this->float, (string)$float);
    }

    public function lessThan(float $float) : void {
        $this->assert($this->float < $float, (string)$this->float, (string)$float);
    }

    public function lessThanOrEqualTo(float $float) : void {
        $this->assert($this->float <= $float, (string)$this->float, (string)$float);
    }
}
