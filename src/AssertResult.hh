<?hh
namespace NUnit;

class AssertResult {
    public function __construct(public string $class, public string $method, public string $file, public int $line) {

    }
}
