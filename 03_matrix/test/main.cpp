#include "matrix.h"


int main() {
    std::cout << "Testing matrix multiplication with int type:" << std::endl;
    matrixMultiplicationUnitTest<int>();

    std::cout<<"1111111"<<std::endl;
    
    std::cout << "\nTesting matrix multiplication with double type:" << std::endl;
    matrixMultiplicationUnitTest<double>();

    std::cout<<"2222222"<<std::endl;
    return 0;
}
