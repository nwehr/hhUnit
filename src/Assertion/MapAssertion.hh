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

class MapAssertion<Tk, Tv> extends Assertion {
    public function __construct(private Map<Tk, Tv> $map, (function(AssertionLocation) : void) $successHandler, (function(AssertionLocation) : void) $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(Map<Tk, Tv> $map) : void {
        $this->assert($this->map == $map);
    }

    public function containsKey(Tk $key) : void {
        $this->assert($this->map->containsKey($key));
    }
}
