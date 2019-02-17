#include <iostream>
#include <vector>
#include<fstream>
#include<string>
#include <algorithm>
template <typename T>
void print_vector(const std::vector<T>& v) {
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}



int main() {
std::ifstream input("temperatures.txt"); //put your program together with thsi file in the same folder.
std::vector<double> temp;
if(input.is_open()){

    while(!input.eof()){
          std::string number;
          double data;
          getline(input,number); //read number
          data = atoi(number.c_str()); //convert to integer
          temp.push_back(data);
    }
  }

  std::sort(temp.begin(),temp.end());
  //print_vector(temp);
  double sum{0};
  for (const double x : temp)
    sum +=x;
  double mean = sum / temp.size();
  std::cout << "Mean =  " << mean << '\n';
  if (((temp.size()/2) % 2) != 0 )
    std::cout << "Median = " << temp[(temp.size()/2) +1] << '\n';
  else
    std::cout << "Median = " <<(temp[(temp.size()/2)] + temp[(temp.size()/2)+1])/2  << '\n';
  return 0;
}
