#include <iostream>
#include <vector>
int main() {

  int num;
  std::cout << "Insert the value: ";
  std::cin >> num;

  std::vector<int> numbers;
  int dim = num -1;
  int cont=2;
  for (int i = 0; i < dim; i++) {
    numbers.push_back(cont);
    cont++;
  }
  return 0;
}
