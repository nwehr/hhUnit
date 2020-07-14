<?hh
namespace hhUnit;

use hhUnit\Assert;

<<TestSuite>>
class StringAssertionTests {
    <<Test>>
    public function equalTo(Assert $assert) : void {
        $assert->string("abc")->equalTo("abc");
    }

    <<Test>>
    public function notEqualTo(Assert $assert) : void {
        $assert->string("abc")->not()->equalTo("123");
    }

    <<Test>>
    public function hasLength(Assert $assert) : void {
        $assert->string("abc")->hasLength(3);
    }

    <<Test>>
    public function matchesPattern(Assert $assert) : void {
        $assert->string("gtolemans@gmail.com")->matchesPattern("/^\S+@\S+\.\S+$/");
    }

    <<Test>>
    public function contains(Assert $assert) : void {
        $assert->string("gtolemans@gmail.com")->contains("gmail");
    }
}
