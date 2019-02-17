#include <iomanip>
#include <iostream>
#include <vector>

void TransposeV(std::vector<int>& psrc, int& R, int& C)
{
	std::vector<int> pcopy;
	pcopy.resize(R*C);
	for(int j=0; j<R*C; j++)
		pcopy[j] = psrc[j];// copy source
	// overwrite source from copy
	int r=0, c=0, tidx=0;
	for(int j=0; j<R*C; j++)
	{
		r = j/C;
		c = j%C;
		tidx = c*R + r;
		psrc[tidx] = pcopy[j];
	}
}

template <typename T>
void print_vector(const std::vector<T>& v, int num) {
  int cont{0};
  for (const auto& x : v){
    if (cont == num) {
        std::cout << '\n';
        cont=0;
      }
    std::cout << x << " ";
    cont++;
  }
  std::cout << '\n';
}

int main() {
  int num_col = 2;
  int num_row = 3;
  std::vector<int> v0{1,2,3,4,5,6};
  std::cout << "The initial matrix is " << '\n';
  print_vector(v0,num_col);
  TransposeV(v0, num_row, num_col);
  std::cout << "The transpose matrix is " << '\n';
  print_vector(v0,num_row);
  return 0;
}













//int* matrix = new int[num_col * num_row]{1,2,3,4,5,6};

/*int* tranMatrix = new int [num_row * num_col]{};
std::cout << "The transpose matrix is " << '\n';
for (int i = 0; i < num_row; ++i) {
  for (int j = 0; j < num_col; ++j) {
    //tranMatrix[j*num_col+i]  = matrix[i*num_col+j];
    tranMatrix[i*num_col+j] = matrix[j*num_col+i];
  }
}*/

/*template <typename T>
void transpose(T* matrix, int num_col, int num_row) {
  unsigned int n_elements =num_row * num_col;
  unsigned int q = n_elements - 1;
  unsigned int i = 0;
  unsigned int k{0};
  do {
    k = (i*num_row) % q;
    while (k>i) k = (num_row*k) % q;
    if (k!=i) {
      Swap(matrix[k], matrix[i]);
      std::cout << "swap mat k e mat i " <<  matrix[k]<< " " << matrix[i]<<'\n';
    }
  } while ( ++i <= (n_elements -2) );

}*/

/*void print_ma(int* p, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      std::cout << std::setw(2) << p[i * col + j] << " ";
    std::cout << std::endl;
  }
}*/
