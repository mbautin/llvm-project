// RUN: rm -rf %t.dir
// RUN: rm -rf %t.dir/foodir
// RUN: rm -rf %t.cdb
// RUN: mkdir -p %t.dir
// RUN: mkdir -p %t.dir/foodir
// RUN: cp %s %t.dir/headerwithdirname_input.cpp
// RUN: mkdir %t.dir/Inputs
// RUN: cp %S/Inputs/foodir %t.dir/Inputs/foodir
// RUN: sed -e "s|DIR|%/t.dir|g" %S/Inputs/headerwithdirname.json > %t.cdb
//
// RUN: clang-scan-deps -compilation-database %t.cdb -j 1 | FileCheck %s

#include <foodir>

// CHECK: headerwithdirname_input{{\.o|.*\.s}}
// CHECK-NEXT: headerwithdirname_input.cpp
// CHECK-NEXT: Inputs{{/|\\}}foodir
