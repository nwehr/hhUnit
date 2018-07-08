<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

use hUnit\Assert;

<<TestSuite>>
class BoolAssertionTestSuite {
    <<Test>>
    public function assertBool(Assert $assert) : void {
        $assert->bool(true)->equalTo(true);
    }

    <<Test>>
    public function assertNotBool(Assert $assert) : void {
        $assert->bool(true)->not()->equalTo(false);
    }
}

<<TestSuite>>
class IntAssertionTestSuite {
    <<Test>>
    public function assertEqualTo(Assert $assert) : void {
        $assert->int(1)->equalTo(1);
    }

    <<Test>>
    public function assertNotEqualTo(Assert $assert) : void {
        $assert->int(1)->not()->equalTo(2);
    }

    <<Test>>
    public function assertGreaterThan(Assert $assert) : void {
        $assert->int(1)->greaterThan(0);
    }

    <<Test>>
    public function assertGreaterThanOrEqualTo(Assert $assert) : void {
        $assert->int(1)->greaterThanOrEqualTo(0);
        $assert->int(1)->greaterThanOrEqualTo(1);
    }

    <<Test>>
    public function assertLessThan(Assert $assert) : void {
        $assert->int(0)->lessThan(1);
    }

    <<Test>>
    public function assertLessThanOrEqualTo(Assert $assert) : void {
        $assert->int(0)->lessThanOrEqualTo(1);
        $assert->int(0)->lessThanOrEqualTo(0);
    }
}

<<TestSuite>>
class FloatAssertionTestSuite {
    <<Test>>
    public function assertFloat(Assert $assert) : void {
        $assert->float(1.1)->equalTo(1.1);
    }

    <<Test>>
    public function assertNotFloat(Assert $assert) : void {
        $assert->float(1.1)->not()->equalTo(1.2);
    }
}

<<TestSuite>>
class StringAssertionTestSuite {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->string("abc")->equalTo("abc");
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->string("abc")->not()->equalTo("123");
    }

    <<Test>>
    public function hasLength(Assert $assert) : void {
        $assert->string("abc")->hasLength(3);
    }

    <<Test>>
    public function matchesPattern(Assert $assert) : void {
        $assert->string("gtolemans@gmail.com")->matchesPattern("/^\S+@\S+\.\S+$/");
    }

    <<Test>>
    public function contains(Assert $assert) : void {
        $assert->string("gtolemans@gmail.com")->contains("gmail");
    }
}

<<TestSuite>>
class ArrayAssertionTestSuite {
    <<Test>>
    public function assertArray(Assert $assert) : void {
        $assert->array([1,2])->equalTo([1,2]);
    }

    <<Test>>
    public function assertNotArray(Assert $assert) : void {
        $assert->array([1,2])->not()->equalTo([2,3]);
    }

    <<Test>>
    public function contains(Assert $assert) : void {
        $assert->array([1,2,3])->contains(1);
    }
}
