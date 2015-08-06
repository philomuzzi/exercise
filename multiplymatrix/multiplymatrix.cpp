#include <iostream>

using namespace std;

const static unsigned int Dimensions = 3;

void multiplyMatrix(const int A[], const int B[], int C[])
{
  for (size_t i = 0, j = 0; i < Dimensions;) {
    int value = 0;
    for (size_t k = 0; k < Dimensions; k++) {
      value += A[i * Dimensions + k] * B[j + k * Dimensions];
    }

    C[i * Dimensions + j] = value;

    if (j + 1 % Dimensions == 0) {
      j = 0;
      i += 1;
    } else {
      j += 1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int A[] = {1,2,3,4,5,6,7,8,1};
  int B[] = {1,2,3,3,2,1,4,5,2};
  int C[9];
  multiplyMatrix(A, B, C);
  for (int i = 0 ; i < 9; ++i)
    cout << C[i] << endl;
  return 0;
}
