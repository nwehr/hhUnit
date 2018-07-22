<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class FloatAssertion extends Assertion {
    public function __construct(private float $float, (function(AssertionLocation) : void) $successHandler, (function(AssertionLocation) : void) $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(float $float) : void {
        $this->assert($this->float == $float);
    }

    public function greaterThan(float $float) : void {
        $this->assert($this->float > $float);
    }

    public function greaterThanOrEqualTo(float $float) : void {
        $this->assert($this->float >= $float);
    }

    public function lessThan(float $float) : void {
        $this->assert($this->float < $float);
    }

    public function lessThanOrEqualTo(float $float) : void {
        $this->assert($this->float <= $float);
    }
}
