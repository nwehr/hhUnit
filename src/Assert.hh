<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/Assertion/Assertion.hh";

class Assert {
    public function __construct(private (function(AssertionLocation) : void) $successHandler, private (function(AssertionLocation) : void) $failureHandler) {}

    public function bool(bool $bool) : BoolAssertion {
        return new BoolAssertion($bool, $this->successHandler, $this->failureHandler);
    }

    public function int(int $int) : IntAssertion {
        return new IntAssertion($int, $this->successHandler, $this->failureHandler); 
    }

    public function float(float $float) : FloatAssertion {
        return new FloatAssertion($float, $this->successHandler, $this->failureHandler);
    }

    public function string(string $string) : StringAssertion {
        return new StringAssertion($string, $this->successHandler, $this->failureHandler);
    }

    public function array(array $array) : ArrayAssertion {
        return new ArrayAssertion($array, $this->successHandler, $this->failureHandler);
    }

    public function map<Tk, Tv>(Map<Tk, Tv> $map) : MapAssertion {
        return new MapAssertion<Tk, Tv>($map, $this->successHandler, $this->failureHandler);
    }

    public function vector<Tv>(Vector<Tv> $vector) : VectorAssertion {
        return new VectorAssertion<Tv>($vector, $this->successHandler, $this->failureHandler);
    }
}
