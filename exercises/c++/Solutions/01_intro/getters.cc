#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>


void get_int(){
	double a;
	std::cout << "Insert an integer number: " << std::endl;
	while (std::cin>>a){
		if (a==floor(a))  {
			std::cout << "This is an integer " << std::endl;
			break;
		} else {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "It is not an integer " << std::endl;
		}
	}
}

void get_double(){
std::cout << "Insert a double number:\n";
double a;
while(std::cin>>a){
	if(a!=(int)a){
		std::cout<<"This is a double!"<<std::endl;
		break;
  }	else{
		std::cin.clear();
		std::cin.ignore();
		std::cout<<"This is not a double "<<std::endl;

	    }
	}
}

int main () {
	get_int();
	get_double();

	return 0;

}
