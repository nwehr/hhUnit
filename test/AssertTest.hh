<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

use hUnit\Assert;

<<TestSuite>>
class BasicSuite {
    <<Test>>
    public function assertBool(Assert $assert) : void {
        $assert->bool(false)->equalsBool(false);
    }

    <<Test>>
    public function assertNotBool(Assert $assert) : void {
        $assert->bool(false)->not()->equalsBool(true);
    }

    <<Test>>
    public function assertInt(Assert $assert) : void {
        $assert->int(1)->equalsInt(1);
    }

    <<Test>>
    public function assertNotInt(Assert $assert) : void {
        $assert->int(1)->not()->equalsInt(2);
    }

    <<Test>>
    public function assertFloat(Assert $assert) : void {
        $assert->float(1.0)->equalsFloat(1.0);
    }

    <<Test>>
    public function assertNotFloat(Assert $assert) : void {
        $assert->float(1.0)->not()->equalsFloat(2.0);
    }
    
    <<Test>>
    public function assertString(Assert $assert) : void {
        $assert->string("abc")->equalsString("abc");
    }

    <<Test>>
    public function assertNotString(Assert $assert) : void {
        $assert->string("abc")->not()->equalsString("123");
    }

    <<Test>>
    public function assertArray(Assert $assert) : void {
        $assert->array([1,2])->equalsArray([1,2]);
    }

    <<Test>>
    public function assertNotArray(Assert $assert) : void {
        $assert->array([1,2])->not()->equalsArray([2,3]);
    }

    <<Test,Skip>>
    public function assertDoesSkip(Assert $assert) : void {
        $assert->bool(true)->equalsBool(false);
    }
}
