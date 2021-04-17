# hhUnit

A unit test framework specifically for the Hack language.

## Test Suites

To create a test suite, write a class with the `<<TestSuite>>` attribute. Individual tests use the `<<Test>>` attribute. You can skip an entire test suite or indivitual tests using the `<<Skip>>` attribute.

```
<?hh
use hhUnit\Assert;

<<TestSuite>>
class MyTestSuite {

    <<Test>>
    public function someTest(Assert $assert) : void {
        $assert->int(1)->equalTo(1);
    }

    <<Test, Skip>>
    public function skippedTest(Assert $assert) : void {
        $assert->bool(true)->not()->equalTo(false);
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
$assert->bool(true)->not()->equalTo(false);
```

### Bool Assertions

```
$assert->bool(true)->equalTo(true);
```

### Int Assertions

```
$assert->int(1)->equalTo(1);

$assert->int(1)->greaterThan(0);
$assert->int(1)->greaterThanOrEqualTo(0);

$assert->int(0)->lessThan(1);
$assert->int(0)->lessThanOrEqualTo(1);
```

### Float Assertions

```
$assert->float(1.1)->equalTo(1.1);

$assert->float(1.2)->greaterThan(1.1);
$assert->float(1.2)->greaterThanOrEqualTo(1.2);

$assert->float(1.1)->lessThan(1.2);
$assert->float(1.1)->lessThanOrEqualTo(1.2);
```

### String Assertions

```
$assert->string("abc")->equalTo("abc");
$assert->string("abc")->hasLength(3);
$assert->string("gtolemans@gmail.com")->contains("gmail");
$assert->string("gtolemans@gmail.com")->matchesPattern("/^\S+@\S+\.\S+$/");
```

### Array Assertions

```
$assert->array([1,2,3])->equalTo([1,2,3]);
$assert->array([1,2,3])->contains(1);
```

### Map Assertions

```
$assert->map<string, string>(Map{"key1" => "value1"})->equalTo(Map{"key1" => "value1"});
$assert->map<string, string>(Map{"key1" => "value1"})->containsKey("key1");
```

### Vector Assertions

```
$assert->vector<string>(Vector{"value1"})->equalTo(Vector{"value1});
$assert->vector<string>(Vector{"value1"})->containsValue("value1");
```

# Install

```
$ composer require nwehr/hhunit
```

#### Run Tests

```
./vendor/bin/hhUnit
```

#### Tester Output

```
Test Suites        : 5
Tests              : 18
Assertions         : 20
Assertion Failures : 0
```

## Ignore

To prevent hhUnit from including individual source files or entire directories add a `.hhunitignore` file in your tests directory.

#### .hhunitignore

```
./IgnoredTestSuite.hh
../ignored_dir
```