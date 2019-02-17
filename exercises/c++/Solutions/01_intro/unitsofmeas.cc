
#include<iostream>
#include<string>
double convertToM(int n) {
  return n * 0.0254;
}

double convertToInch (int n){
  return n/ 0.0254;
}

int main() {

  std::string num,unit;
  double result;

  std::cout << "Insert the number with its proper unit (inch or m): " << '\n';
  std::cin >>num ;
  std::cin >>unit;
  std::string::size_type sz;   // alias of size_t
  double number =  std::stod (num,&sz);
  if (unit.compare("inch")==0)  result = convertToM(number);

  else if (unit.compare("m")==0) result = convertToInch(number);

  else std::cout << "Unit not recognize" << '\n';

  std::cout << "The result is " <<result <<  '\n';

}
