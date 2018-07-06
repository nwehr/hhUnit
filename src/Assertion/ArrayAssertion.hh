<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class ArrayAssertion extends Assertion {
    public function __construct(private array $array, Signal $success, Signal $failure) {
        parent::__construct($success, $failure);
    }

    public function equalToArray(array $array) : void {
        $this->backtrace(\debug_backtrace());
        $this->assert($this->array == $array);
    }
}
