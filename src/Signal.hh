<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion/AssertionLocation.hh";

// interface Signal {
//     public function connect((function(void) : void)) : void;  
//     public function emit() : void;
// }

class Signal {
    public function __construct(protected Vector<(function(AssertionLocation) : void)> $slots = Vector{}) {}

    public function connect((function(AssertionLocation) : void) $slot) {
        $this->slots->add($slot);
    }

    public function disconnectAll() {
        $this->slots->clear();
    }
 
    public function emit(AssertionLocation $location) {
        foreach($this->slots as $slot) {
            $slot($location);
        }
    }
}
