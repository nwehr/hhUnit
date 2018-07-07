<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class BoolAssertion extends Assertion {
    public function __construct(private bool $bool, Signal $success, Signal $failure) {
        parent::__construct($success, $failure);
    }

    public function equalToBool(bool $bool) : void {
        $this->assert($this->bool == $bool);
    }
}
