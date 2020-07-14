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

class StringAssertion extends Assertion {
    public function __construct(private string $string, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(string $string) : void {
        $this->assert($this->string == $string, $this->string, $string);
    }

    public function hasLength(int $length) : void {
        $this->assert(\strlen($this->string) == $length, (string)\strlen($this->string), (string)$length);
    }

    public function matchesPattern(string $pattern) : void {
        $this->assert((bool)\preg_match($pattern, $this->string), $this->string, $pattern);
    }

    public function contains(string $needle) : void {
        $this->assert((bool)\strstr($this->string, $needle), $this->string, $needle);
    }
}
