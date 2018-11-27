<?hh // decl
namespace hUnit\Tests\Options;

use hUnit\Assert;

require_once dirname(__FILE__) . "/../src/Options.hh";

class TestableOptions extends \hUnit\Options {
    public function __construct(array $opt) {
        parent::__construct($opt);
    }
}

<<TestSuite>>
class OptionsTests {
    <<Test>>
    public function shouldListTests_ReturnsTrue(Assert $assert) : void {
        $opt = [
            "l" => false
        ];

        $shouldListTests = (new TestableOptions($opt))->listTests();

        $assert->bool($shouldListTests)->equalTo(true);
    }

    <<Test>>
    public function shouldShowHelp_ReturnsTrue(Assert $assert) : void {
        $opt = [
            "h" => false
        ];

        $shouldShowHelp = (new TestableOptions($opt))->showHelp();

        $assert->bool($shouldShowHelp)->equalTo(true);
    }

    <<Test>>
    public function sourceFileDirectories_ReturnsVector(Assert $assert) : void {
        $opt = [
            "d" => "/var/www/tests"
        ];

        $directoryPaths = (new TestableOptions($opt))->directoryPaths();

        $assert->vector<string>($directoryPaths)->equalTo(Vector{"/var/www/tests"});
    }

    <<Test>>
    public function namespaceNames_ReturnsVector(Assert $assert) : void {
        $opt = [
            "n" => "hUnit\Tests\TypeAssertions"
        ];

        $namespaceNames = (new TestableOptions($opt))->namespaceNames();

        $assert->vector<string>($namespaceNames)->equalTo(Vector{"hUnit\Tests\TypeAssertions"});
    }
}
