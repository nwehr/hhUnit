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

class IntAssertion extends Assertion {
    public function __construct(private int $int, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(int $int) : void {
        $this->assert($this->int == $int, (string)$this->int, (string)$int);
    }

    public function greaterThan(int $int) : void {
        $this->assert($this->int > $int, (string)$this->int, (string)$int);
    }

    public function greaterThanOrEqualTo(int $int) : void {
        $this->assert($this->int >= $int, (string)$this->int, (string)$int);
    }

    public function lessThan(int $int) : void {
        $this->assert($this->int < $int, (string)$this->int, (string)$int);
    }

    public function lessThanOrEqualTo(int $int) : void {
        $this->assert($this->int <= $int, (string)$this->int, (string)$int);
    }
}
