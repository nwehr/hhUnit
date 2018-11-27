<?hh
//
// Copyright 2018 hUnit project developers.
// See COPYRIGHT.txt
// 
// This file is part of the hUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hUnit;

require_once dirname(__FILE__) . "/FileSystemScanner.hh";
require_once dirname(__FILE__) . "/ReflectionTestSuite.hh";

class TestSuiteLoader {
    protected static ?TestSuiteLoader $instance = null; 

    protected Vector<ReflectionTestSuite> $testSuites;

    protected function __construct(Vector<string> $classNames) {
        $classes = $classNames->map((string $className) ==> new ReflectionTestSuite($className));

        $this->testSuites = $classes->filter((ReflectionTestSuite $class) ==> {
            $attributes = new Map($class->getAttributes());

            if($attributes->containsKey("TestSuite")) {
                return true;
            } else {
                return false;
            }
        });
    }

    public static function instance() : TestSuiteLoader {
        if(!self::$instance) {
            $directoryPaths = Options::instance()->directoryPaths();
            $sourcePaths = (new FileSystemScanner())->getSourcePaths($directoryPaths);

            foreach($sourcePaths as $path) {
                require_once $path;
            }

            $classNames = new Vector(get_declared_classes());
            
            self::$instance = new self($classNames);
        }

        return self::$instance;
    }

    public function getTestSuites() : Vector<ReflectionTestSuite> {
        return $this->testSuites;
    }

    public function getTestSuitesByNamespace(string $namespaceName) : Vector<ReflectionTestSuite> {
        return $this->testSuites->filter((ReflectionTestSuite $testSuite) ==> {
            if($testSuite->getNamespaceName() == $namespaceName) {
                return true;
            } else {
                return false;
            }
        });
    }

    public function getNamespaceNames() : Vector<string> {
        $namespaces = Vector{};

        foreach($this->testSuites as $testSuite) {
            if($namespaces->linearSearch($testSuite->getNamespaceName()) == -1) {
                $namespaces->add($testSuite->getNamespaceName());
            }
        }

        return $namespaces;
    }
}