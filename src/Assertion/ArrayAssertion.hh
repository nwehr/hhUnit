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

class ArrayAssertion extends Assertion {
    public function __construct(private varray<mixed> $array, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(varray<mixed> $array) : void {
        $this->assert($this->array == $array, "true", "unknown");
    }

    public function contains(mixed $needle) : void {
        $this->assert(\in_array($needle, $this->array), "true", "unknown");
    }
}
