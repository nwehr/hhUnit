<?hh // decl
namespace hUnit\Tests\Application;

use hUnit\Assert;

class TestableTestSuiteLoader extends \hUnit\TestSuiteLoader {
    public function __construct(Vector<string> $classNames) {
        parent::__construct($classNames);
    }
}

<<TestSuite>>
class TestSuiteLoaderTests {
    <<Test>>
    public function getTestSuites_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hUnit\Tests\Application\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getTestSuites()->map((\hUnit\ReflectionTestSuite $testSuite) ==> $testSuite->getShortName());

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"TestSuiteLoaderTests"});
    }

    <<Test>>
    public function getTestSuitesByNamespace_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hUnit\Tests\Application\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getTestSuitesByNamespace("hUnit\Tests\Application")->map((\hUnit\ReflectionTestSuite $testSuite) ==> $testSuite->getShortName());

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"TestSuiteLoaderTests"});
    }

    <<Test>>
    public function getNamespaceNames_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hUnit\Tests\Application\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getNamespaceNames();

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"hUnit\Tests\Application"});
    }
}
