/*Reverse order with vectors*/
#include<iostream>
#include<vector>
int main() {
  int n;
  std::cout << "Dimension of the array: " << '\t';
  std::cin >> n;
  std::vector<int> numbers;
  int num;
  for (int i = 0; i < n; i++) {
    std::cout << "Insert the value number: \t";
    std::cin >> num;
    numbers.push_back(num);
  }
  for (auto ir = numbers.crbegin(); ir != numbers.crend(); ++ir)
    std::cout << *ir << " ";
  return 0;
}
