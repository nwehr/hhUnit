<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

class ReflectionTestSuite extends \ReflectionClass {
	public function getCategories() : Vector<string> {
		$attributes = new Map<string, mixed>($this->getAttributes());
		
		if(!$attributes->containsKey("Categories")) {
			return Vector{};
		}
		
		return new Vector<string>($attributes["Categories"]);
	}
	
	public function shouldSkip() : bool {
		$attributes = new Map<string, mixed>($this->getAttributes());
		
		return $attributes->containsKey("Skip");
	}

	public function shouldSkipMethod(\ReflectionMethod $method) : bool {
		$attributes = new Map<string, mixed>($method->getAttributes());
	
		return $attributes->containsKey("Skip");
	}

	public function getTestMethods() : Vector<\ReflectionMethod> {
		$methods = new Vector<\ReflectionMethod>($this->getMethods());

		return $methods->filter((\ReflectionMethod $method) ==> {
            $attributes = new Map<string, mixed>($method->getAttributes());

            if($attributes->containsKey("Test")) {
                return true;
            } else {
                return false;
            }
        });
	}
}
