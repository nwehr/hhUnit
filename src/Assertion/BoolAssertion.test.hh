<?hh // partial
namespace hhUnit;

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
