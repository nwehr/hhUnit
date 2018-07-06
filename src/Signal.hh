<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

class Signal {
    public function __construct(protected Vector<(function(AssertResult) : void)> $slots = Vector{}) {}

    public function connect((function(AssertResult) : void) $slot) {
        $this->slots->add($slot);
    }
 
    public function emit(AssertResult $assertResult) {
        foreach($this->slots as $slot) {
            $slot($assertResult);
        }
    }
}
