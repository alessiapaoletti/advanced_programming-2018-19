#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print_vector(const std::vector<T>& v) {
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> words;
  std::string singleWord;
  std::cout << "Insert the words: " << '\n';
  while (std::cin>>singleWord){
    if (words.empty()) words.push_back(singleWord);
    else {
      unsigned int i{0};
      //If it isn't the first word we check if that word is not in the vector
      while (singleWord != words[i] && i<words.size())  i++;
      //If we have check all the words in the vector and the new word is not present we add it
      if (i == words.size()) words.push_back(singleWord);
    }
  }
  std::cout << "\nFinal vector without repeated words :  " << '\n';
  print_vector(words);
  return 0;
}
