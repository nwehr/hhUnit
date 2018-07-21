<?hh
use hUnit\Assert;

<<TestSuite>>
class IntTestSuite {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->int(1)->equalTo(1);
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->int(1)->not()->equalTo(2);
    }

    <<Test>>
    public function greaterThan(Assert $assert) : void {
        $assert->int(1)->greaterThan(0);
    }

    <<Test>>
    public function greaterThanOrEqualTo(Assert $assert) : void {
        $assert->int(1)->greaterThanOrEqualTo(0);
        $assert->int(1)->greaterThanOrEqualTo(1);
    }

    <<Test>>
    public function lessThan(Assert $assert) : void {
        $assert->int(0)->lessThan(1);
    }

    <<Test>>
    public function lessThanOrEqualTo(Assert $assert) : void {
        $assert->int(0)->lessThanOrEqualTo(1);
        $assert->int(0)->lessThanOrEqualTo(0);
    }
}
