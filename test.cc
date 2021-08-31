#include <iostream>
#include "hex_formatter.hh"

struct test1 {
    test1() {
        std::cout << "test1 construct" << std::endl;
    }    
      int a = 0;
      int b = 1;
  };

  struct test2 {
      test2() {
          std::cout << "test2 construct " << std::endl;
      }
      long c = 2;
      long d = 4;
  };

  class test3 {
      public:
      test3() {}
      int a = 0;
      union {
          test1 t1;
          test2 t2;
      };
  };

  void func_test() {
    // test3 t3{};
    // std::cout << std::hex << "t3.a: " << t3.a << std::endl;
    // std::cout << std::hex << "t3.t1.a: " << t3.t1.a << std::endl;
    // std::cout << std::hex << "t3.t1.b: " << t3.t1.b << std::endl;
    // std::cout << std::hex << "t3.t2.c: " << t3.t2.c << std::endl;
    // std::cout << std::hex << "t3.t2.d: " << t3.t2.d << std::endl;
    union un {
          test1 t1;
          test2 t2{};
    }t4{};
    std::cout << std::hex << "t4.t1.a: " << t4.t1.a << std::endl;
    std::cout << std::hex << "t4.t1.b: " << t4.t1.b << std::endl;
    std::cout << std::hex << "t4.t2.c: " << t4.t2.c << std::endl;
    std::cout << std::hex << "t4.t2.d: " << t4.t2.d << std::endl;
    //   double c;
    //   auto addr = (unsigned long)&t3;
    //   std::cout << std::hex << "addr of t3 is    : " << (unsigned long )addr << std::endl;
    //   std::cout << std::hex << "addr of t3.a is  : " << (unsigned long )(&t3.a) << std::endl;
    //   std::cout << std::hex << "addr of t3.t1 is : " << (unsigned long )(&t3.t1) << std::endl;
    //   std::cout << std::hex << "addr of t3.t1.a is : " << (unsigned long )(&t3.t1.a) << std::endl;
    //   std::cout << std::hex << "addr of t3.t1.b is : " << (unsigned long )(&t3.t1.b) << std::endl;
    //   std::cout << std::hex << "addr of t3.t2 is : " << (unsigned long )(&t3.t2) << std::endl;
    //   std::cout << std::hex << "addr of t3.t2.c is : " << (unsigned long )(&t3.t2.c) << std::endl;
    //   std::cout << std::hex << "addr of t3.t2.d is : " << (unsigned long )(&t3.t2.d) << std::endl;
    //   std::cout << CompilerVm::hex_formatter::dump_to_string((void *)(addr - 256), 512);
    //   std::cout << std::hex << "addr of c is : " << (unsigned long)&c << std::endl;

    //   std::cout << std::hex << "c: " << c << std::endl;
  }