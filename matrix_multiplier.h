#ifndef MATRIX_MULTIPLIER_H
#define MATRIX_MULTIPLIER_H

#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows_, cols_;

    // Private setter functions
    void setRows(size_t r) { rows_ = r; }
    void setCols(size_t c) { cols_ = c; }

public:
    // Default constructor for an empty matrix (0x0)
    Matrix() : rows_(0), cols_(0) {}

    // Constructor to initialize the matrix with a given size
    Matrix(size_t r, size_t c) : rows_(r), cols_(c), data(r, std::vector<int>(c)) {}

    // Constructor to initialize the matrix with a 2D vector
    Matrix(const std::vector<std::vector<int>>& mat) : data(mat) {
        setRows(mat.size());
        setCols(mat.empty() ? 0 : mat[0].size());
    }

    // Constructor to initialize from an initializer list
    Matrix(std::initializer_list<std::initializer_list<int>> initList) {
        for (const auto& row : initList) {
            data.emplace_back(row);
        }
        setRows(data.size());
        setCols(data.empty() ? 0 : data[0].size());
    }

    // Getter functions
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }

    // Overload the () operator for easy access to elements
    int& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    // Const version of the () operator
    const int& operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    // Overload the equality operator (==) for matrix comparison
    bool operator==(const Matrix& other) const;

    // Function for matrix multiplication (naive)
    friend Matrix multiplyMatrices(const Matrix& A, const Matrix& B);
	
	// Winograd's Algorithm for multiplying matrices
    friend Matrix winogradMultiply(const Matrix& A, const Matrix& B);
};

#endif // MATRIX_MULTIPLIER_H

