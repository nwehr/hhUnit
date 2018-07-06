# NDUnit

A unit test framework specifically for the Hack language.

## Build

```
docker build -t ndunit ./
```

## Usage

Share your whole project directory to `/unit-tests` using volumes. NDUnit will recursively search all directories and files for test suites.

```
docker run --rm -t -v $(pwd)/test:/unit-tests ndunit
```

## Test Suites

To create a test suite, write a class with the `<<TestSuite>>` attribute. Individual tests use the `<<Test>>` attribute. You can skip an entire test suite or indivitual tests using the `<<Skip>>` attribute.

```
<?hh
use NDUnit\Assert;

<<TestSuite>>
class MyTestSuite {

    <<Test>>
    public function someTest(Assert $assert) : void {
        $assert->int(1)->equalsInt(1);
    }

    <<Test, Skip>>
    public function skippedTest(Assert $assert) : void {
        $assert->bool(true)->equalsBool(false);
    }
}
```