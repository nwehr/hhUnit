<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion.hh";

class StringAssertion extends Assertion {
    public function __construct(private string $string, Signal $success, Signal $failure) {
        parent::__construct($success, $failure);
    }

    public function equalToString(string $string) : void {
        $this->assert($this->string == $string);
    }
}
