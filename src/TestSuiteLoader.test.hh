<?hh 
namespace hhUnit;

class TestableTestSuiteLoader extends TestSuiteLoader {
    public function __construct(Vector<string> $classNames) {
        parent::__construct($classNames);
    }
}

<<TestSuite>>
class TestSuiteLoaderTests {
    <<Test>>
    public function getTestSuites_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hhUnit\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getTestSuites()->map((ReflectionTestSuite $testSuite) ==> $testSuite->getShortName());

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"TestSuiteLoaderTests"});
    }

    <<Test>>
    public function getTestSuitesByNamespace_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hhUnit\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getTestSuitesByNamespace("hhUnit")->map((ReflectionTestSuite $testSuite) ==> $testSuite->getShortName());

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"TestSuiteLoaderTests"});
    }

    <<Test>>
    public function getNamespaceNames_ReturnsVector(Assert $assert) : void {
        $testSuiteLoader = new TestableTestSuiteLoader(Vector{"hhUnit\TestSuiteLoaderTests"});

        $testSuiteNames = $testSuiteLoader->getNamespaceNames();

        $assert->vector<string>($testSuiteNames)->equalTo(Vector{"hhUnit"});
    }
}
