#include <iostream>

/*Function that prints the array and only the non-zero elements */
void printarray (int *array, size_t size) {
    for (size_t k{0}; k<size; k++){
      if (array[k]!=0) std::cout << array[k] << '\t';
    }
}
/*Function that returns true if n is a prime number, false otherwise */
bool isPrime(int n) {
  char flag{0};
  if (n == 0) return false;
  else if (n==1) return false;
  else {
    for (size_t i{2}; i<(size_t)n; i++ ) {
      if ((n%i) == 0) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) return false;
  else return true;
}

int main() {
  /*I do an array of 100 elements because
  for sure there will be less than 100 prime numbers in the first 100 integer
   numbers*/
  int *primes{new int[100]};
  bool  res;
  int i{0};
  for (size_t num{0}; num<=100; num++) {
    res = isPrime(num);
    if (res) {
      primes[i]= num;
      i++;
    }
  }
  printarray(primes,100);
  delete[] primes;
  return 0;
}
