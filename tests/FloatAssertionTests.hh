<?hh // decl
namespace hUnit\Tests\TypeAssertions;

use hUnit\Assert;

<<TestSuite>>
class FloatAssertionTests {
    <<Test>>
    public function oneEqualToOne(Assert $assert) : void {
        $assert->float(1.1)->equalTo(1.1);
    }

    <<Test>>
    public function oneNotEqualToTwo(Assert $assert) : void {
        $assert->float(1.1)->not()->equalTo(1.2);
    }

    <<Test>>
    public function twoGreaterThanOne(Assert $assert) : void {
        $assert->float(1.2)->greaterThan(1.1);
    }

    <<Test>>
    public function twoGreaterThanOrEqualToOne(Assert $assert) : void {
        $assert->float(1.2)->greaterThanOrEqualTo(1.1);
        $assert->float(1.2)->greaterThanOrEqualTo(1.2);
    }

    <<Test>>
    public function oneLessThanTwo(Assert $assert) : void {
        $assert->float(1.1)->lessThan(1.2);
    }

    <<Test>>
    public function oneLessThanOrEqualToTwo(Assert $assert) : void {
        $assert->float(1.1)->lessThanOrEqualTo(1.2);
        $assert->float(1.1)->lessThanOrEqualTo(1.1);
    }
}