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

class IntAssertion extends Assertion {
    public function __construct(private int $int, (function(AssertionLocation) : void) $successHandler, (function(AssertionLocation) : void) $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(int $int) : void {
        $this->assert($this->int == $int);
    }

    public function greaterThan(int $int) : void {
        $this->assert($this->int > $int);
    }

    public function greaterThanOrEqualTo(int $int) : void {
        $this->assert($this->int >= $int);
    }

    public function lessThan(int $int) : void {
        $this->assert($this->int < $int);
    }

    public function lessThanOrEqualTo(int $int) : void {
        $this->assert($this->int <= $int);
    }
}
