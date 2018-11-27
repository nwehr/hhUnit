<?hh // decl
namespace hUnit\Tests\Reflection;

use hUnit\Assert;

<<TestSuite, Skip>>
class SkippedTests {
    <<Test>>
    public function foo(Assert $assert) : void {

    }

    <<Test, Skip>>
    public function bar(Assert $assert) : void {
        
    }

    public function thisIsNotATest() : void {

    }
}

<<TestSuite>>
class ReflectionTestSuiteTests {
    <<Test>>
    public function shouldSkip_ReturnsTrue(Assert $assert) : void {
        $testSuite = new \hUnit\ReflectionTestSuite("hUnit\Tests\Reflection\SkippedTests");

        $shouldSkip = $testSuite->shouldSkip();

        $assert->bool($shouldSkip)->equalTo(true);
    }

    <<Test>>
    public function shouldSkipMethod_ReturnsTrue(Assert $assert) : void {
        $testSuite = new \hUnit\ReflectionTestSuite("hUnit\Tests\Reflection\SkippedTests");

        $shouldSkipMethod = $testSuite->shouldSkipMethod($testSuite->getMethod("bar"));

        $assert->bool($shouldSkipMethod)->equalTo(true);
    }

    <<Test>>
    public function getTestMethods_ReturnsVector(Assert $assert) : void {
        $testSuite = new \hUnit\ReflectionTestSuite("hUnit\Tests\Reflection\SkippedTests");

        $testMethods = $testSuite->getTestMethods()->map((\ReflectionMethod $method) ==> $method->getName());

        $assert->vector<string>($testMethods)->equalTo(Vector{"foo", "bar"});
    }
}
