<?hh 
namespace hhUnit;

use hhUnit\Assert;

<<TestSuite>>
class MapAssertionTests {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->map<string, string>(Map{"key1" => "value1"})->equalTo(Map{"key1" => "value1"});
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->map<string, string>(Map{"key1" => "value1"})->not()->equalTo(Map{"key1" => "value2"});
    }

    <<Test>>
    public function containsKey(Assert $assert) : void {
        $assert->map<string, string>(Map{"key1" => "value1"})->containsKey("key1");
    }
}
