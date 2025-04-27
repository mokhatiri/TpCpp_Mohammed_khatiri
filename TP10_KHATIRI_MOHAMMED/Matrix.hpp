#pragma once
#include <array>
#include <iostream>
#include <cstddef>

template<typename T, std::size_t M, std::size_t N>
class Matrix {
private:
    std::array<T, M * N> data{};
public:
    void set(std::size_t i, std::size_t j, const T& value) {
        data[i * N + j] = value;
    }

    T get(std::size_t i, std::size_t j) const {
        return data[i * N + j];
    }

    Matrix<T, M, N> add(const Matrix<T, M, N>& other) const {
        Matrix<T, M, N> result;
        for (std::size_t i = 0; i < M * N; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
};

// Specialisation (par autre classe) pour addition incompatible
template<typename T, std::size_t M1, std::size_t N1, std::size_t M2, std::size_t N2>
struct MatrixAdder {
    static Matrix<T, M1, N1> add(const Matrix<T, M1, N1>&, const Matrix<T, M2, N2>&) {
        static_assert(M1 == M2 && N1 == N2, "Erreur : Dimensions incompatibles !");
        return Matrix<T, M1, N1>(); // Juste pour éviter erreur de compilation
    }
};