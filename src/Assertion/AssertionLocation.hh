<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

class AssertionLocation {
    public function __construct(public string $testSuite, public string $test, public string $file, public int $line) {

    }
}
