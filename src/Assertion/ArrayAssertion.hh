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

class ArrayAssertion extends Assertion {
    public function __construct(private array $array) {}

    public function equalTo(array $array) : void {
        $this->assert($this->array == $array);
    }

    public function contains(mixed $needle) : void {
        $this->assert(in_array($needle, $this->array));
    }
}
