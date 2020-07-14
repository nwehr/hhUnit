<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hhUnit;

require_once \dirname(__FILE__) . "/Assertion/Assertion.hh";

class Assert {
    public function __construct(private SuccessHandlerFn $successHandler, private FailureHandlerFn $failureHandler) {}

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

    public function array(varray<mixed> $array) : ArrayAssertion {
        return new ArrayAssertion($array, $this->successHandler, $this->failureHandler);
    }

    public function map<Tk, Tv>(Map<Tk, Tv> $map) : MapAssertion<Tk, Tv> {
        return new MapAssertion<Tk, Tv>($map, $this->successHandler, $this->failureHandler);
    }

    public function vector<Tv>(Vector<Tv> $vector) : VectorAssertion<Tv> {
        return new VectorAssertion<Tv>($vector, $this->successHandler, $this->failureHandler);
    }
}
