<?hh
namespace NUnit;

require_once "/usr/local/nunit/src/AssertResult.hh";
require_once "/usr/local/nunit/src/Signal.hh";

class Assert {
    private string $file = "";
    private int $line = 0;

    private ?bool $bool;
    private ?int $int;
    private ?float $float;
    private ?string $string;

    private bool $not = false;

    public Signal $success;
    public Signal $failure;

    public function __construct(private string $class, private string $method) {
        $this->success = new Signal();
        $this->failure = new Signal();
    }

    private function recordBacktrace(array $backtrace) {
        $this->file = $backtrace[0]["file"];
        $this->line = $backtrace[0]["line"];
    }

    private function success() {
        $this->success->emit(new AssertResult($this->class, $this->method, $this->file, $this->line));
    }

    private function failure() {
        $this->failure->emit(new AssertResult($this->class, $this->method, $this->file, $this->line));
    }

    private function eval(bool $eval) : void {
        if($this->not ? !$eval : $eval) {
            $this->success();
        } else {
            $this->failure();
        }
    }

    public function not() : Assert {
        $this->not = true;
        return $this;
    }

    public function bool(bool $bool) : Assert {
        $this->recordBacktrace(\debug_backtrace());
        $this->bool = $bool;

        return $this;
    }

    public function int(int $int) : Assert {
        $this->recordBacktrace(\debug_backtrace());
        $this->int = $int;

        return $this;
    }

    public function float(float $float) : Assert {
        $this->recordBacktrace(\debug_backtrace());
        $this->float = $float;

        return $this;
    }

    public function string(string $string) : Assert {
        $this->recordBacktrace(\debug_backtrace());
        $this->string = $string;

        return $this;
    }

    public function equalsBool(bool $bool) : Assert {
        $this->eval($this->bool == $bool);
        return $this;
    }

    public function equalsInt(int $int) : Assert {
        $this->eval($this->int == $int);
        return $this;
    }

    public function equalsFloat(float $float) : Assert {
        $this->eval($this->float == $float);
        return $this;
    }

    public function equalsString(string $string) : Assert {
        $this->eval($this->string == $string);
        return $this;
    }
}
