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

class BoolAssertion extends Assertion {
    public function __construct(private bool $bool, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(bool $bool) : void {
        $this->assert($this->bool == $bool, $this->bool ? "true" : "false", $bool ? "true" : "false");
    }
}
