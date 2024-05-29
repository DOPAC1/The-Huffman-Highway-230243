#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<double>(c, 0));
    }

    void input() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void print() const {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    Matrix matA(m, n);
    Matrix matB(n, m);
    Matrix matC(m, m);

    matA.input();
    matB.input();

    matC = matA * matB;

    cout << "Matrix A:" << endl;
    matA.print();
    cout << "Matrix B:" << endl;
    matB.print();
    cout << "Matrix C (A * B):" << endl;
    matC.print();

    return 0;
}
