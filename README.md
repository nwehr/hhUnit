# hUnit

A unit test framework specifically for the Hack language.

## Build

```
docker build -t hunit .
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
        $assert->int(1)->equalToInt(1);
    }

    <<Test, Skip>>
    public function skippedTest(Assert $assert) : void {
        $assert->bool(true)->equalToBool(false);
    }
}
```

## Assertions

All of the scalar types are available in the `Assert` class. 

- `bool`
- `int`
- `float`
- `string`
- `array`

Any assertion may be negated by calling `not()` before the final assertion method. 

```
$assert->bool(true)->not()->equalToBool(false);
```

### Bool Assertions

```
$assert->bool(true)->equalToBool(true);
```

### Int Assertions

```
$assert->int(1)->equalToInt(1);

$assert->int(1)->greaterThanInt(0);
$assert->int(1)->greaterThanOrEqualToInt(0);

$assert->int(0)->lessThanInt(1);
$assert->int(0)->lessThanOrEqualToInt(1);
```

### Float Assertions

```
$assert->float(1.1)->equalToFloat(1.1);
```

### String Assertions

```
$assert->string("abc")->equalToString("abc");
```

### Array Assertions

```
$assert->array([1,2,3])->equalToArray([1,2,3]);
```