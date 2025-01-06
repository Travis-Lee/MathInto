#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

// 矩阵模板类
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;


public:
    // 构造函数，创建一个 rows 行 cols 列的矩阵
    Matrix(size_t rows, size_t cols);
    // 析构函数声明
    ~Matrix();
    // 重载 () 运算符，用于访问矩阵元素
    T& operator()(size_t i, size_t j);
    const T& operator()(size_t i, size_t j) const;
    // 获取矩阵的行数
    size_t getRows() const;
    // 获取矩阵的列数
    size_t getCols() const;
    // 获取矩阵的大小
    size_t size() const;
    // 矩阵乘法运算符 * 重载
    Matrix<T> operator*(const Matrix<T>& other) const;
    // 打印矩阵元素
    void print() const;
};

// 单元测试函数声明
template <typename T>
void matrixMultiplicationUnitTest();

#endif
