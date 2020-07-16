<?hh // partial
namespace hhUnit;

use hhUnit\Assert;

<<TestSuite>>
class ArrayAssertionTests {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->array(varray<int>[1,2])->equalTo(varray<int>[1,2]);
    }
    
    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->array(varray<int>[1,2])->not()->equalTo(varray<int>[2,3]);
    }

    <<Test>>
    public function contains(Assert $assert) : void {
        $assert->array(varray<int>[1,2,3])->contains(1);
    }
}
