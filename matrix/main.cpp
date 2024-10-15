#include <iostream>
#include <string>
#include <fstream>`
#include <string>
#include <sstream>
#include <vector>
#include "MyMatrix.h"


void readFile(std::vector<std::string>& input, std::ifstream& file) {
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        input.push_back(line);
    }
}

int main()
{
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    std::ifstream file("input1.txt");
    readFile(input1, file);

    file.close();
    file.open("input2.txt");

    readFile(input2, file);



    MyMatrix matrix1(input1);
    MyMatrix matrix2(input2);
    std::string str = "2 2      2 2\n 2 0  \t  2 2\n 2 3 0 3\n 2 5 5 0";
    MyMatrix strMatrix(str);
    std::cout << "mat by str\n";
    std::cout << strMatrix;

    std::cout << "mat1\n";
    std::cout << matrix1;
    std::cout << "mat2\n";
    std::cout << matrix2;

    std::cout << "mat copy\n";
    MyMatrix copyMat(matrix1);
    std::cout << copyMat;


    std::cout << matrix1.getTransportedCopy();

    std::cout << "transpone\n";
    matrix1.TransponeMe();
    std::cout << matrix1;

    /*std::cout << "add\n";
    std::cout << matrix1 + matrix2 << std::endl;
    std::cout << "mul\n";
    std::cout << matrix1 * matrix2 << std::endl;
    
    //double det = *matrix1.calcDeterminant();
    std::cout << matrix1.calcDeterminant() << std::endl;*/
}
