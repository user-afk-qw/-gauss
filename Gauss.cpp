#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
    const int N = 3;
    
void print(double mat[N][N+1]) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j == N) cout << "| ";
            cout << setw(10) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для решения СЛАУ методом Гаусса
bool gauss(double mat[N][N+1], double result[N]) {
    // Прямой ход метода Гаусса
    for (int i = 0; i < N; i++) {
        // Поиск максимального элемента в столбце для уменьшения ошибок
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(mat[k][i]) > fabs(mat[maxRow][i])) {
                maxRow = k;
            }
        }
        
        // Перестановка строк
        if (maxRow != i) {
            for (int k = i; k <= N; k++) {
                swap(mat[i][k], mat[maxRow][k]);
            }
        }
        
        // Приведение матрицы к треугольному виду
        for (int k = i + 1; k < N; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= N; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }
    
    // Обратный ход метода Гаусса
    for (int i = N - 1; i >= 0; i--) {
        result[i] = mat[i][N];
        for (int j = i + 1; j < N; j++) {
            result[i] -= mat[i][j] * result[j];
        }
        result[i] /= mat[i][i];
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double matrix[N][N+1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11}, 
        {-2, 1, 2, -3}    
    };
    
    double result[N];
    
    cout << "Исходная расширенная матрица:" << endl;
    print(matrix);
    
    if (gauss(matrix, result)) {
        cout << "Треугольная матрица после прямого хода:" << endl;
        print(matrix);
        
        cout << "Решение системы:" << endl;
        for (int i = 0; i < N; i++) {
            cout << "x" << i+1 << " = " << result[i] << endl;
        }
    }
    return 0;
}
