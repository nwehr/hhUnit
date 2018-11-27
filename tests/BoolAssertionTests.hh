<?hh // decl
namespace hUnit\Tests\TypeAssertions;

use hUnit\Assert;

<<TestSuite>>
class BoolAssertionTests {
    <<Test>>
    public function trueEqualToTrue(Assert $assert) : void {
        $assert->bool(true)->equalTo(true);
    }

    <<Test>>
    public function trueNotEqualToFalse(Assert $assert) : void {
        $assert->bool(true)->not()->equalTo(false);
    }
}
