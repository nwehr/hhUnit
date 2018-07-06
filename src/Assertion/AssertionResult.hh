<?hh
//
// Copyright 2018 Nathan Wehr. All rights reserved.
// See LICENSE.txt
// 

namespace hUnit;

class AssertionResult {
    public function __construct(public string $class, public string $method, public string $file, public int $line) {

    }
}
