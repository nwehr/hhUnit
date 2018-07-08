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

class BoolAssertion extends Assertion {
    public function __construct(private bool $bool, AssertSignals $signals) {
        parent::__construct($signals);
    }

    public function equalTo(bool $bool) : void {
        $this->assert($this->bool == $bool);
    }
}
