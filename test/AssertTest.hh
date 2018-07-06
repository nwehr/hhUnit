<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

use hUnit\Assert;

<<TestSuite>>
class BoolAssertionTestSuite {
    <<Test>>
    public function assertBool(Assert $assert) : void {
        $assert->bool(true)->EqualToBool(true);
    }

    <<Test>>
    public function assertNotBool(Assert $assert) : void {
        $assert->bool(true)->not()->EqualToBool(false);
    }
}

<<TestSuite>>
class IntAssertionTestSuite {
    <<Test>>
    public function assertEqualTo(Assert $assert) : void {
        $assert->int(1)->equalToInt(1);
    }

    <<Test>>
    public function assertNotEqualTo(Assert $assert) : void {
        $assert->int(1)->not()->EqualToInt(2);
    }

    <<Test>>
    public function assertGreaterThan(Assert $assert) : void {
        $assert->int(1)->greaterThanInt(0);
    }

    <<Test>>
    public function assertGreaterThanOrEqualTo(Assert $assert) : void {
        $assert->int(1)->greaterThanOrEqualToInt(0);
        $assert->int(1)->greaterThanOrEqualToInt(1);
    }

    <<Test>>
    public function assertLessThan(Assert $assert) : void {
        $assert->int(0)->lessThanInt(1);
    }

    <<Test>>
    public function assertLessThanOrEqualTo(Assert $assert) : void {
        $assert->int(0)->lessThanOrEqualToInt(1);
        $assert->int(0)->lessThanOrEqualToInt(0);
    }
}

<<TestSuite>>
class FloatAssertionTestSuite {
    <<Test>>
    public function assertFloat(Assert $assert) : void {
        $assert->float(1.0)->equalToFloat(1.0);
    }

    <<Test>>
    public function assertNotFloat(Assert $assert) : void {
        $assert->float(1.0)->not()->equalToFloat(2.0);
    }
}

<<TestSuite>>
class StringAssertionTestSuite {
    <<Test>>
    public function assertString(Assert $assert) : void {
        $assert->string("abc")->equalToString("abc");
    }

    <<Test>>
    public function assertNotString(Assert $assert) : void {
        $assert->string("abc")->not()->equalToString("123");
    }
}

<<TestSuite>>
class ArrayAssertionTestSuite {
    <<Test>>
    public function assertArray(Assert $assert) : void {
        $assert->array([1,2])->equalToArray([1,2]);
    }

    <<Test>>
    public function assertNotArray(Assert $assert) : void {
        $assert->array([1,2])->not()->equalToArray([2,3]);
    }
}

<<TestSuite>>
class BasicTestSuite {
    <<Test, Skip>>
    public function skipMe(Assert $assert) : void {
        $assert->bool(true)->equalToBool(false);
    }
}