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

class VectorAssertion<Tv> extends Assertion {
    public function __construct(private Vector<Tv> $vector, (function(AssertionLocation) : void) $successHandler, (function(AssertionLocation) : void) $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(Vector<Tv> $vector) : void {
        $this->assert($this->vector == $vector);
    }

    public function containsValue(Tv $value) : void {
        $this->assert($this->vector->linearSearch($value) != -1);
    }
}
