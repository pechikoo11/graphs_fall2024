#include <iostream>
#include <vector>

int main() {
    int N, check = 0, answ=3001;
    std::cin >> N;
    std::vector <std::vector <int>> V(N,std::vector <int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> V[i][j];
        } }
    
    for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = 0; i2 < N; i2++) {
            for (int i3 = 0; i3 < N; i3++) {
                if (i1 != i2 && i2 != i3 && i3 != i1) {
                check = V[i1][i2] + V[i2][i3] + V[i3][i1];
                if (check < answ) answ = check;
            } } }
    } std::cout << answ;
}
