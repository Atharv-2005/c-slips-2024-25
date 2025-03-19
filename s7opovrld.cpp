//Create a class Matrix and Write a C++ program to perform following functions:
//a. To accept a Matrix
//b. To display a Matrix
//c. Overload unary minus ‘–‘ operator to calculate transpose of a Matrix
//d. Overload binary multiplication '*’ operator to calculate multiplication of two matrices

#include <iostream>
using namespace std;

class Matrix {
private:
    int **mat;
    int rows, cols;

public:
    // Constructor to initialize matrix size
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        mat = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new int[cols];
        }
    }

    // Destructor to free memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Function to accept matrix elements
    void accept() {
        cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display the matrix
    void display() const {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload unary minus to transpose the matrix
    Matrix operator-() {
        Matrix transposed(cols, rows); // Transposed matrix will have swapped rows and cols
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.mat[j][i] = mat[i][j];
            }
        }
        return transposed;
    }

    // Overload binary multiplication * to multiply two matrices
    Matrix operator*(const Matrix& m) {
        if (cols != m.rows) {
            throw invalid_argument("Matrix dimensions are not compatible for multiplication.");
        }
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }

    // Getter functions for row and column count
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    int r1, c1, r2, c2;

    // Accept first matrix dimensions and elements
    cout << "Enter number of rows and columns for matrix 1: ";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.accept();

    // Accept second matrix dimensions and elements (for multiplication)
    cout << "Enter number of rows and columns for matrix 2: ";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.accept();

    // Display the entered matrices
    cout << endl;
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();

    // Transpose of matrix 1 using unary minus operator
    Matrix transposeMat1 = -mat1;
    cout << "Transpose of Matrix 1:" << endl;
    transposeMat1.display();

    // Multiply matrix 1 and matrix 2
    try {
        Matrix product = mat1 * mat2;
        cout << "Product of Matrix 1 and Matrix 2:" << endl;
        product.display();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}


