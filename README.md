# hUnit

A unit test framework specifically for the Hack language.

## Build hUnit

```
docker build -t registry.gitlab.com/nwehr/hunit .
```

## Build/Run hunit-tester

```
docker build -t hunit-tester -f Dockerfile.hunit-tester .
docker run -t --rm hunit-tester
```

## Dockerfile.hunit-tester

To use hUnit in your own project, it is recommended that you create your own `Dockerfile.hunit-tester` and build/run the tester (See above).

```
FROM registry.gitlab.com/nwehr/hunit

COPY /path/to/your/tests /usr/local/tests

# place your source code where it normally would be in your production container
COPY /path/to/your/sourceFiles /path/to/your/sourceFiles 
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

## Ignore

To prevent hUnit from initially including unwanted source files, add a `.hunitignore` file in your tests directory.

```
./IgnoredTestSuite.hh
../IgnoredDir
```