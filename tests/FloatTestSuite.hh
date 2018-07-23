<?hh // decl
use hUnit\Assert;

<<TestSuite>>
class FloatTestSuite {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->float(1.1)->equalTo(1.1);
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->float(1.1)->not()->equalTo(1.2);
    }

    <<Test>>
    public function greaterThan(Assert $assert) : void {
        $assert->float(1.2)->greaterThan(1.1);
    }

    <<Test>>
    public function greaterThanOrEqualTo(Assert $assert) : void {
        $assert->float(1.2)->greaterThanOrEqualTo(1.1);
        $assert->float(1.2)->greaterThanOrEqualTo(1.2);
    }

    <<Test>>
    public function lessThan(Assert $assert) : void {
        $assert->float(1.1)->lessThan(1.2);
    }

    <<Test>>
    public function lessThanOrEqualTo(Assert $assert) : void {
        $assert->float(1.1)->lessThanOrEqualTo(1.2);
        $assert->float(1.1)->lessThanOrEqualTo(1.1);
    }
}