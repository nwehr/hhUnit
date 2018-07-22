<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
//  

namespace hUnit;

require_once dirname(__FILE__) . "/Assert.hh";

class Exit {
    const OK = 0;
    const ERROR = 1;
}

class hUnit {
    private Vector<\ReflectionClass> $testSuites;

    private int $numTestSuites = 0;
    private int $numTests = 0;
    private int $numAssertions = 0;
    private int $numAssertionFailures = 0;

    public function __construct(Vector<\ReflectionClass> $classes) {
        $this->testSuites = $this->getTestSuitesFromClasses($classes);
    }

    private function getTestSuitesFromClasses(Vector<\ReflectionClass> $classes) : Vector<\ReflectionClass> {
        $testSuites = $classes->filter((\ReflectionClass $class) ==> {
            $attributes = new Map($class->getAttributes());

            if($attributes->containsKey("TestSuite") && !$attributes->containsKey("Skip")) {
                return true;
            } else {
                return false;
            }
        });

        $this->numTestSuites += $testSuites->count();

        return $testSuites;
    }

    private function getTestsFromMethods(Vector<\ReflectionMethod> $methods) : Vector<\ReflectionMethod> {
        $tests = $methods->filter((\ReflectionMethod $method) ==> {
            $attributes = new Map($method->getAttributes());

            if($attributes->containsKey("Test") && !$attributes->containsKey("Skip")) {
                return true;
            } else {
                return false;
            }
        });

        $this->numTests += $tests->count();

        return $tests;
    }

    private function printStats() : void {
        printf("Test Suites        : %d\n", $this->numTestSuites);
        printf("Tests              : %d\n", $this->numTests);
        printf("Assertions         : %d\n", $this->numAssertions);
        printf("Assertion Failures : %d\n", $this->numAssertionFailures);
    }

    private function printSuccess(string $testSuiteName, string $testName, AssertionBacktrace $backtrace) : void {
        printf("\033[1;32mSUCCESS\n%s::%s at %s:%d\033[0m\n\n", $testSuiteName, $testName, $backtrace->file, $backtrace->line);
    }

    private function printFailure(string $testSuiteName, string $testName, AssertionBacktrace $backtrace) : void {
        printf("\033[1;31mFAILED \n%s::%s at %s:%d\033[0m\n\n", $testSuiteName, $testName, $backtrace->file, $backtrace->line);
    }

    public function run() : int {
        foreach($this->testSuites as $testSuite) {
            $testSuiteInstance = $testSuite->newInstance();

            $tests = $this->getTestsFromMethods(new Vector($testSuite->getMethods()));
            
            foreach($tests as $test) {
                $handleSuccess = (AssertionBacktrace $backtrace) ==> {
                    ++$this->numAssertions;
                };

                $handleFailure = (AssertionBacktrace $backtrace) ==> {
                    ++$this->numAssertions;
                    ++$this->numAssertionFailures;

                    $this->printFailure($testSuite->getName(), $test->getName(), $backtrace);
                };

                $assert = new Assert($handleSuccess, $handleFailure);
                
                $test->invokeArgs($testSuiteInstance, [$assert]);
            }
        }

        $this->printStats();

        return $this->numAssertionFailures ? Exit::ERROR : Exit::OK;
    }
}
