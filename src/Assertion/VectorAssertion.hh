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

class VectorAssertion<Tv> extends Assertion {
    public function __construct(private Vector<Tv> $vector, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(Vector<Tv> $vector) : void {
        $this->assert($this->vector == $vector, $this->vector->__toString(), $vector->__toString());
    }

    public function containsValue(Tv $value) : void {
        $this->assert($this->vector->linearSearch($value) != -1, $this->vector->__toString(), (string)$value);
    }
}
