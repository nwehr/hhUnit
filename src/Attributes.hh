<?hh
//
// Copyright 2018-2020 Nathan Wehr.
// See COPYRIGHT.txt
// 
// This file is part of the hhUnit project and subject to license terms.
// See LICENSE.txt
// 

namespace hhUnit;

interface TestSuite extends \HH\ClassAttribute {}
interface Test extends \HH\MethodAttribute {}
interface Skip extends \HH\ClassAttribute, \HH\MethodAttribute {}
