#include <iostream>
#include <vector>

int main() {
    int row, column;
    std::cin >> row >> column;
    std::vector <std::vector <int>> mat (row, std::vector <int> (column, 0)),
                                    varpath (row, std::vector <int> (column, -1));
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cin >> mat[i][j];
        }
    }

    for (int j = 1; j < column; ++j) {
        for (int i = 0; i < row; ++i) {
            int min = mat[i][j-1];
            int prev = i;
            if (i > 0 && mat[i-1][j-1] <= min) {
                min = mat[i-1][j-1];
                prev = i - 1;
            } 
            if (i < row - 1 && mat[i+1][j-1] < min) {
                min = mat[i+1][j-1];
                prev = i + 1;
            }
            mat[i][j] += min;
            varpath[i][j] = prev;
        }
    }

    int answ = mat[0][column - 1];
    int index = 0;
    for (int i = 1; i < row; ++i) {
        if (answ > mat[i][column-1]) {
            answ = mat[i][column-1];
            index = i;
        } 
    }

    std::vector <int> path (column, 0);
    for (int j = column-1; j >= 0; --j) {
        path[j] = index;
        index = varpath[index][j];
    }

    for (int step : path) {
        std::cout << step + 1 << ' ';
    }
    std::cout << '\n' << answ << '\n';
}
