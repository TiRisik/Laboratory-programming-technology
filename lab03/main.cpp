#include <iostream>
#include <vector>
using namespace std;

class Matrix{

private:

    int** matrix;
    int size_x;
    int size_y;

public:

    Matrix(int** a, int x, int y){
        size_x = x;
        size_y = y;
        matrix = new int*[x];
        for (int i=0; i!= x; i++)
            matrix[i] = new int[y];
        for (int i=0; i!= x; i++)
            for (int j=0; j!= y; j++)
                matrix[i][j] = a[i][j];

    }

    void PrintMatrix(){
        cout<<endl;
        for (int j = 0; j != size_x; j++) {
            for (int i = 0; i != size_y; i++)
                cout << matrix[j][i] << ' ';
            cout << endl;
        }
    }

    Matrix operator += (Matrix& r) {
        Matrix res = r;
        for (int j = 0; j != res.size_x; j++)
            for (int i = 0; i != res.size_y; i++)
                matrix[j][i] += res.matrix[j][i];
        return {matrix, size_x, size_y};
    }

    Matrix operator -= (Matrix& r) {
        Matrix res = r;
        for (int j = 0; j != res.size_x; j++) {
            int size_matrix;
            if (res.size_y < size_y) size_matrix = res.size_y;
            else size_matrix = size_y;
            for (int i = 0; i != size_matrix; i++)
                matrix[j][i] -= res.matrix[j][i];
        }
        return {matrix, size_x, size_y};
    }

    int operator * (Matrix& r) {
        Matrix res = r;
        int scalar = 0;
        for (int j = 0; j != res.size_x; j++) {
            int size_matrix;
            if (res.size_y < size_y) size_matrix = res.size_y;
            else size_matrix = size_y;
            for (int i = 0; i != size_matrix; i++)
                scalar += matrix[j][i] * res.matrix[j][i];
        }
        return scalar;
    }

    Matrix operator *= (int a) {
        for (int j = 0; j != size_x; j++)
            for (int i = 0; i != size_y; i++)
                matrix[j][i] *= a;
        return {matrix, size_x, size_y};
    }

    Matrix operator / (int a) {
        for (int j = 0; j != size_x; j++)
            for (int i = 0; i != size_y; i++)
                matrix[j][i] *= a;
        return {matrix, size_x, size_y};
    }

};

int main(){
    int** matrix1 = new int*[3];
    for (int i=0; i!= 3; i++)
        matrix1[i] = new int[3];
    for (int i=0; i!= 3; i++)
        for (int j=0; j!= 3; j++)
            matrix1[i][j] = j + i + 4;
    int** matrix2 = new int*[3];
    for (int i=0; i!= 3; i++)
        matrix2[i] = new int[3];
    for (int i=0; i!= 3; i++)
        for (int j=0; j!= 3; j++)
            matrix2[i][j] = j + i - 7;
    Matrix m1(matrix1, 3, 3);
    Matrix m2(matrix2, 3, 3);
    cout<<"matrix 1: ";
    m1.PrintMatrix();
    cout<<"matrix 2: ";
    m2.PrintMatrix();
    m1 *= 4;
    cout<<"matrix 1 * 4: ";
    m1.PrintMatrix();
    int scalar = m2 * m1;
    cout<<"matrix 1 * matrix 2: "<<scalar<<endl;
    m2 -= m1;
    cout<<"matrix 2 - matrix 1: ";
    m2.PrintMatrix();
    m1 += m2;
    cout<<"matrix 1 + matrix 2: ";
    m1.PrintMatrix();
    m1 / 4;
    cout<<"matrix 1 / 4: ";
    m1.PrintMatrix();
    return 0;
}
