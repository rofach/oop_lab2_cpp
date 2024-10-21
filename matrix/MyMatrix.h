#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <iostream>
#include <vector>
#include <sstream>
#include <optional>

class MyMatrix {
private:
    double** m_matrix;
    int m_rows, m_cols;
    double* determinant;
    
    void createMatrix(int rows, int cols);

    

    int countNumbersInString(const std::string& line);

    double** getTrasnportedArray();

    void addRow(double** matrix, int row1, int row2, double num);

    void addCol(double** matrix, int col1, int col2, double num);

    void removeVoidLines(std::vector<std::string>& str);

    void isRectangular(std::vector<std::string>& str);

    void initMatrixByVector(std::vector<std::string>& str);

    std::vector<std::string> convertStringToVector(const std::string &str);

public:
    MyMatrix(MyMatrix& matrix);

    MyMatrix(double** matrix, int rows, int cols);

    MyMatrix(std::vector<std::string>& str);

    MyMatrix(std::string str);
    
    ~MyMatrix();

    static double** createArray(int rows, int cols);

    int getHeight();
    
    int getWidth();

    void setValue(int i, int j, double num);

    double getValue(int i, int j);

    

    MyMatrix getTransportedCopy();

    void transposeMe();

    friend std::ostream& operator<<(std::ostream& out, const MyMatrix& matrix);
   
    double& operator()(const int i, const int j);

    double calcDeterminant();
    
};

MyMatrix operator+(MyMatrix& matrix1, MyMatrix& matrix2);
MyMatrix operator*(MyMatrix& matrix1, MyMatrix& matrix2);


#endif
