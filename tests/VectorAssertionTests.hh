<?hh // decl
namespace hUnit\Tests\TypeAssertions;

use hUnit\Assert;

<<TestSuite>>
class VectorAssertionTests {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->vector<string>(Vector{"value1", "value2"})->equalTo(Vector{"value1", "value2"});
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->vector<string>(Vector{"value1", "value2"})->not()->equalTo(Vector{"value1", "value2", "value3"});
    }

    <<Test>>
    public function containsValue(Assert $assert) : void {
        $assert->vector<string>(Vector{"value1", "value2"})->containsValue("value1");
    }
}
