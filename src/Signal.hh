<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

class Signal {
    public function __construct(protected Vector<(function(AssertionResult) : void)> $slots = Vector{}) {}

    public function connect((function(AssertionResult) : void) $slot) {
        $this->slots->add($slot);
    }
 
    public function emit(AssertionResult $result) {
        foreach($this->slots as $slot) {
            $slot($result);
        }
    }
}
