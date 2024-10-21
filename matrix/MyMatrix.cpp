
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "MyMatrix.h"


void MyMatrix::createMatrix(int rows, int cols) {
    m_matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        m_matrix[i] = new double[cols];
}

double** MyMatrix::createArray(int rows, int cols) {
    double** array = new double* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new double[cols];
    }
    return array;
}

int MyMatrix::getHeight() {
    return m_rows;
}
int MyMatrix::getWidth() {
    return m_cols;
}


std::optional<double> determinant = std::nullopt;

MyMatrix::MyMatrix(MyMatrix& matrix) : m_rows(matrix.m_rows), m_cols(matrix.m_cols)
{
    int h = matrix.getHeight();
    int w = matrix.getWidth();
    m_matrix = createArray(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            m_matrix[i][j] = matrix.m_matrix[i][j];
        }
    }
    
}
MyMatrix::MyMatrix(double** matrix, int rows, int cols) : m_rows(rows), m_cols(cols)
{
    createMatrix(rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++) {
            m_matrix[i][j] = matrix[i][j];
        }
    }
}
int MyMatrix::countNumbersInString(const std::string& line) {
    std::istringstream stream(line);
    double number;
    int count = 0;
    while (stream >> number) {
        count++;
    }

    return count;
}

void MyMatrix::removeVoidLines(std::vector<std::string>& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i].empty())
            str.erase(str.begin() + i--);
    }
}

int getLineLength(std::string &str) {
    std::stringstream input(str);
    int count = 0;
    int a;
    while (input) {
        input >> a;
        count++;
    }
    return count;
}

void MyMatrix::isRectangular(std::vector<std::string>& str) {
    int length = getLineLength(str[0]);
    for (int i = 1; i < m_rows; i++) {       
        if (getLineLength(str[i]) != length)
            throw ("is not rectangular");
    }
}

void MyMatrix::initMatrixByVector(std::vector<std::string>& str) {
    removeVoidLines(str);
    m_rows = str.size();
    m_cols = countNumbersInString(str[0]);
    createMatrix(m_rows, m_cols);
    isRectangular(str);
    for (int i = 0; i < m_rows; i++) {
        std::istringstream input(str[i]);
        for (int j = 0; j < m_cols; j++)
            input >> m_matrix[i][j];
    }
}

MyMatrix::MyMatrix(std::vector<std::string>& str)
{
    initMatrixByVector(str);
}
std::vector<std::string> MyMatrix::convertStringToVector(const std::string& str) {
    std::istringstream input(str);
    std::string line;
    std::vector<std::string> v;
    while (std::getline(input, line)) {
        v.push_back(line);
    }
    return v;
}

MyMatrix::MyMatrix(std::string str) 
{
    std::vector<std::string> v = convertStringToVector(str);
    initMatrixByVector(v);
}


void MyMatrix::setValue(int i, int j, double num) {
    m_matrix[i][j] = num;
}

double MyMatrix::getValue(int i, int j) {
    return m_matrix[i][j];
}


std::ostream& operator <<(std::ostream& out, const MyMatrix& matrix) {
    for (int i = 0; i < matrix.m_rows; i++) {
        for (int j = 0; j < matrix.m_cols; j++)
        {
            out << matrix.m_matrix[i][j];
            if (j < matrix.m_cols - 1)
                out << "\t";
        }
        out << std::endl;


    }
    return out;
}

double& MyMatrix::operator()(const int i, const int j) {
    return m_matrix[i][j];
}



MyMatrix operator+(MyMatrix& matrix1, MyMatrix& matrix2) {
    if (matrix1.getHeight() != matrix2.getHeight() && matrix2.getWidth() != matrix2.getHeight())
        throw "не рівні";

    int rows = matrix1.getHeight();
    int cols = matrix2.getWidth();



    double **newMatrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix[i][j] = matrix1(i, j) + matrix2(i, j);
        }
    }


    return MyMatrix(newMatrix, rows, cols);

}

MyMatrix operator*(MyMatrix& matrix1, MyMatrix& matrix2) {
    if (matrix1.getWidth() != matrix2.getHeight()) throw "impossible";

    int rows = matrix1.getHeight();
    int cols = matrix2.getWidth();

    double** newMatrix = MyMatrix::createArray(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix[i][j] = 0;
            for (int k = 0; k < matrix2.getHeight(); k++) {
                
                newMatrix[i][j] += matrix1(i, k) * matrix2(k, j);
            }
        }
    }

    return MyMatrix(newMatrix, rows, cols);

}
double** MyMatrix::getTrasnportedArray() {
    int rows = m_rows;
    int cols = m_cols;
    double** newMatrix = createArray(cols, rows);
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            newMatrix[i][j] = m_matrix[j][i];
        }
    }
    return newMatrix;
}

MyMatrix MyMatrix::getTransportedCopy() {
    return MyMatrix(getTrasnportedArray(), m_cols, m_rows);
}

void MyMatrix::transposeMe() {
    MyMatrix temp = getTransportedCopy();
    

    for (int i = 0; i < m_rows; ++i) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;

    int rows = temp.m_rows;
    int cols = temp.m_cols;

    this->m_matrix = new double*[rows];
    for (int i = 0; i < rows; i++)
        m_matrix[i] = new double[cols];
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m_matrix[i][j] = temp.m_matrix[i][j];
        }
    }
    
    this->m_rows = rows;
    this->m_cols = cols;
    
}

void MyMatrix::addRow(double** matrix, int row1, int row2, double num) {

    for (int i = 0; i < m_rows; i++) {
        matrix[row2][i] += matrix[row1][i] * num;
    }
}

void MyMatrix::addCol(double** matrix, int col1, int col2, double num) {
    for (int i = 0; i < m_rows; i++) {
        matrix[i][col2] += matrix[i][col1] * num;
    }
}

double MyMatrix::calcDeterminant() {

    if (m_rows != m_cols) throw "the matrix is not square";
    double det = 1;
    if (m_cols > 2) {
        double** cmatrix = createArray(m_rows, m_cols);

        for (int i = 0; i < m_rows; i++) {
            std::copy(m_matrix[i], m_matrix[i] + m_cols, cmatrix[i]);
        }
        
        for (int i = 0; i < m_cols; i++) {
            if (cmatrix[i][i] == 0) {
                for (int k = i; k < m_rows; k++) {
                    if (cmatrix[i][k] != 0) {
                        addCol(cmatrix, k, i, 1);
                        break;
                    }

                }
                if (cmatrix[i][i] == 0)
                {
                    determinant = 0;
                    return 0;
                }
            }
            for (int j = i + 1; j < m_rows; j++) {
                double m = -cmatrix[j][i] / cmatrix[i][i];
                addRow(cmatrix, i, j, m);
            }

            
            
        }
        for (int i = 0; i < m_rows; i++) {
            det *= cmatrix[i][i];
        }
        //
        
        determinant = &det;
    }
    else {
        det = m_matrix[0][0] * m_matrix[1][1] - (m_matrix[0][1] * m_matrix[1][0]);
        determinant = &det;
        
    }

    return *determinant;
}

MyMatrix::~MyMatrix() {
    for (int i = 0; i < m_rows; i++) {
        delete[] m_matrix[i];
    }

    delete[] m_matrix;
}
