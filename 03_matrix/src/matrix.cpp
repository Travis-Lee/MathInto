#include "matrix.h"


// 矩阵类的构造函数
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

// 析构函数的实现
template <typename T>
Matrix<T>::~Matrix() {}

template <typename T>
size_t Matrix<T>::getRows() const {
    return rows;
}


template <typename T>
size_t Matrix<T>::getCols() const {
    return cols;
}

template <typename T>
size_t Matrix<T>::size() const {
    return rows*cols;
}

template <typename T>
T& Matrix<T>::operator()(size_t i, size_t j) {
    return data[i][j];
}


template <typename T>
const T& Matrix<T>::operator()(size_t i, size_t j) const {
    return data[i][j];
}


template <typename T>
void Matrix<T>::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// 矩阵乘法运算符 * 重载
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols!= other.getRows()) {
        throw std::runtime_error("Invalid matrix dimensions for multiplication");
    }
    Matrix<T> result(rows, other.getCols());
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.getCols(); ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}


// 单元测试函数实现
template <typename T>
void matrixMultiplicationUnitTest() {
    // 测试正常矩阵乘法
    Matrix<T> A(2, 3);
    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;


    Matrix<T> B(3, 2);
    B(0, 0) = 7; B(0, 1) = 8;
    B(1, 0) = 9; B(1, 1) = 10;
    B(2, 0) = 11; B(2, 1) = 12;


    std::cout << "Matrix A:" << std::endl;
    A.print();


    std::cout << "Matrix B:" << std::endl;
    B.print();


    try {
        Matrix<T> C = A * B;
        std::cout << "Matrix C = A * B:" << std::endl;
        C.print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    // 测试矩阵乘法维度不匹配的情况
    Matrix<T> D(2, 2);
    D(0, 0) = 1; D(0, 1) = 2;
    D(1, 0) = 3; D(1, 1) = 4;


    Matrix<T> E(3, 3);
    E(0, 0) = 5; E(0, 1) = 6; E(0, 2) = 7;
    E(1, 0) = 8; E(1, 1) = 9; E(1, 2) = 10;
    E(2, 0) = 11; E(2, 1) = 12; E(2, 2) = 13;


    std::cout << "Matrix D:" << std::endl;
    D.print();


    std::cout << "Matrix E:" << std::endl;
    E.print();


    try {
        Matrix<T> F = D * E;
    } catch (const std::runtime_error& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
}


// 显式实例化 Matrix 类和单元测试函数，针对 int 和 double 类型
template class Matrix<int>;
template void matrixMultiplicationUnitTest<int>();


template class Matrix<double>;
template void matrixMultiplicationUnitTest<double>();


