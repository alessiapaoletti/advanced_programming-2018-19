#include <iostream>

/*Function that inizializes the array with the elements that the user type*/
template <typename T, typename S>
T* iniz(S size) {
  T* array{new int[size]};
  for (int i=0; i<size; i++) {
      std::cout << "Insert the value number: \t";
      std::cin >> array[i];
    }
  return array;
}

/*Function that prints the array in the reverse order */ 
template<typename T, typename S>
void printrev(T* array, S size) {
  int dim = (int)size - 1;
  for (int i = dim; i>=0; i--){
    std::cout << array[i] << "\t";
  }
}

int main() {
  int n;
  std::cout << "Dimension of the array: " << '\t';
  std::cin >> n;
  int* array = iniz<int>(n);
  printrev(array,n);
  delete[] array;
  return 0;
}
