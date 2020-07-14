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

class MapAssertion<Tk, Tv> extends Assertion {
    public function __construct(private Map<Tk, Tv> $map, SuccessHandlerFn $successHandler, FailureHandlerFn $failureHandler) {
        parent::__construct($successHandler, $failureHandler);
    }

    public function equalTo(Map<Tk, Tv> $map) : void {
        $this->assert($this->map == $map, $this->map->__toString(), $map->__toString());
    }

    public function containsKey(Tk $key) : void {
        $this->assert($this->map->containsKey($key), $this->map->__toString(), (string)$key);
    }
}
