<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
//  

namespace hhUnit;

require_once \dirname(__FILE__) . "/Assert.hh";

class Exit {
    const OK = 0;
    const ERROR = 1;
}

class hhUnit {
    protected int $numTestSuites = 0;
    protected int $numTests = 0;

    protected int $numAssertions = 0;
    protected int $numAssertionFailures = 0;

    protected int $numSkippedTestSuites = 0;
    protected int $numSkippedTests = 0;

    public function __construct(protected Vector<ReflectionTestSuite> $testSuites) {
        $this->numTestSuites = $this->testSuites->count();
    }

    protected function printStats() : void {
        \printf("Test Suites         : %d\n", $this->numTestSuites);
        \printf("Tests               : %d\n", $this->numTests);
        \printf("Assertions          : %d\n", $this->numAssertions);
        \printf("Assertion Failures  : %d\n", $this->numAssertionFailures);
        \printf("Skipped Test Suites : %d\n", $this->numSkippedTestSuites);
        \printf("Skipped Tests       : %d\n", $this->numSkippedTests);
    }

    protected function printSuccess(string $testSuiteName, string $testName, AssertionBacktrace $backtrace) : void {
        \printf("\033[1;32mSUCCESS\n%s::%s in %s:%d\033[0m\n\n", $testSuiteName, $testName, $backtrace->file, $backtrace->line);
    }

    protected function printFailure(string $testSuiteName, string $testName, AssertionBacktrace $backtrace, string $lhs, string $rhs) : void {
        $pathTokens = \explode("/", $backtrace->file);
        $fileName = $pathTokens[\count($pathTokens) - 1];

        \printf("\033[1;31mFAILED \n%s::%s in %s:%d\ncomparing '%s' and '%s'\033[0m\n\n", $testSuiteName, $testName, $fileName, $backtrace->line, $lhs, $rhs);
    }

    public function run() : int {
        foreach($this->testSuites as $testSuite) {
            if($testSuite->shouldSkip()) {
                ++$this->numSkippedTestSuites;
                continue;
            }

            $testSuiteInstance = $testSuite->newInstance();

            $testMethods = $testSuite->getTestMethods();

            $this->numTests += $testMethods->count();
            
            foreach($testMethods as $testMethod) {
                if($testSuite->shouldSkipMethod($testMethod)) {
                    ++$this->numSkippedTests;
                    continue;
                }

                $handleSuccess = (AssertionBacktrace $backtrace) ==> {
                    ++$this->numAssertions;
                };

                $handleFailure = (AssertionBacktrace $backtrace, string $lhs, string $rhs) ==> {
                    ++$this->numAssertions;
                    ++$this->numAssertionFailures;

                    $this->printFailure($testSuite->getName(), $testMethod->getName(), $backtrace, $lhs, $rhs);
                };

                $assert = new Assert($handleSuccess, $handleFailure);
                
                $testMethod->invokeArgs($testSuiteInstance, varray<mixed>[$assert]);
            }
        }

        $this->printStats();

        return $this->numAssertionFailures ? Exit::ERROR : Exit::OK;
    }
}
