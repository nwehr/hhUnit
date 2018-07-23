<?hh // decl
use hUnit\Assert;

<<TestSuite>>
class BoolTestSuite {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->bool(true)->equalTo(true);
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->bool(true)->not()->equalTo(false);
    }
}
