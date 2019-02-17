/* Take a simple program (e.g., the hello world one) and put one at a time the following errors. Compile it and try to understand the error messages. If you have both g++ and clang++ compare the messages from the two compilers.
typos in function name (e.g., c0ut)
typos in variable name
forget to put ;
forget to #include <iostream>
declare a variable with illegal name like int double {0};
pass wrong type of argument to a function */

#include <iostream>
int sum (int a, int b) {
	return a+b;
}

int main() {
  int first{3};
  int second{0};
  std::cout << "Hello world\n " << first<<std::endl; 
  std::cout << "Hello world\n" << sum(3, 3)<<std::endl;

  return 0;
}

// if I write std:c0out << "Hello world\n"; --> the compiler says 'c0out' is not a member of 'std'
// if I write   std::cout << "Hello world\n" << furst; while my variable name is 'first' the error is 'furst' was not declared in this scope
// if don't put ; the error is expected ; before 'return'
// if I forget to #include <iostream> the error is 'cout' is not a member of 'std'
// if I declare int dobule second{0} the error is two or more data types in declaration of 'second'
// if I call the function sum with (3) , the error is too few arguments to function 'int sum(int,int)'
