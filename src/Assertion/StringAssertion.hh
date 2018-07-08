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

class StringAssertion extends Assertion {
    public function __construct(private string $string, AssertSignals $signals) {
        parent::__construct($signals);
    }

    public function equalTo(string $string) : void {
        $this->assert($this->string == $string);
    }

    public function hasLength(int $length) : void {
        $this->assert(strlen($this->string) == $length);
    }

    public function matchesPattern(string $pattern) : void {
        $this->assert((bool)preg_match($pattern, $this->string));
    }

    public function contains(string $needle) : void {
        $this->assert((bool)strstr($this->string, $needle));
    }
}
