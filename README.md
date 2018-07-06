# NDUnit

A unit test framework specifically for the Hack language.

## Build

```
docker build -t hunit ./
```

## Usage

Share your whole project directory to `/unit-tests` using volumes. hUnit will recursively search all directories and files for test suites.

```
docker run --rm -t -v $(pwd)/test:/unit-tests hunit
```

## Test Suites

To create a test suite, write a class with the `<<TestSuite>>` attribute. Individual tests use the `<<Test>>` attribute. You can skip an entire test suite or indivitual tests using the `<<Skip>>` attribute.

```
<?hh
use hUnit\Assert;

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