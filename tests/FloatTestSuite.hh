<?hh
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
}