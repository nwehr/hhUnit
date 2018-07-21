<?hh
use hUnit\Assert;

<<TestSuite>>
class ArrayTestSuite {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->array([1,2])->equalTo([1,2]);
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->array([1,2])->not()->equalTo([2,3]);
    }

    <<Test>>
    public function contains(Assert $assert) : void {
        $assert->array([1,2,3])->contains(1);
    }
}
