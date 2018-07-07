<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class IntAssertion extends Assertion {
    public function __construct(private int $int, Signal $success, Signal $failure) {
        parent::__construct($success, $failure);
    }

    public function equalToInt(int $int) : void {
        $this->assert($this->int == $int);
    }

    public function greaterThanInt(int $int) : void {
        $this->assert($this->int > $int);
    }

    public function greaterThanOrEqualToInt(int $int) : void {
        $this->assert($this->int >= $int);
    }

    public function lessThanInt(int $int) : void {
        $this->assert($this->int < $int);
    }

    public function lessThanOrEqualToInt(int $int) : void {
        $this->assert($this->int <= $int);
    }
}
