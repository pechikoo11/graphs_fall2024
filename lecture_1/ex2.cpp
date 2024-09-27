#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    M*=2;
    int answ = 0;
    std::vector <int> vect(M);
    for (int s = 0; s < M ; s += 1) {
        std::cin >> vect[s];
    } for (int i = 1; i <= N; i += 1) {
        for (int j = 0; j < M; j += 1) {
            if (vect[j] == i) answ++;
        } std::cout << answ << " ";
        answ = 0; } 
}
