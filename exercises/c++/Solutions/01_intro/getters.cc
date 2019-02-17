#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>


int get_int(){
	double a;
	std::cout << "Insert an integer number: " << '\n';
	while (std::cin>>a){
		if (a==floor(a))  break;
		std::cin.clear();
		std::cin.ignore();
	}
	return a;
}
//
//
// double get_double(){
//
//
// }

int main () {
	int resultInt = get_int();
	std::cout << "The integer number is: " << resultInt<< '\n';
	//double resultDouble = get_double();

	return 0;

}
