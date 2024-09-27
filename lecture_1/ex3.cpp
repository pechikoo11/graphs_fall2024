#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, answ = 0, check;
    std::cin >> N;
    std::vector <int> bridges(0);
    std::vector <int> colors(N);
    
    for (int i1 = 1; i1 <= N; i1 += 1) {
        for (int j1 = 1; j1 <= N; j1 += 1) {
            std::cin >> check;
            if (check == 1) {
                bridges.push_back(i1);
                bridges.push_back(j1);
        } } }

    for (int i2 = 0; i2 < N; i2 += 1){
        std::cin >> colors [i2];
    } 
    
    for (int i = 0; i < bridges.size(); i += 2) {
            if (colors[bridges[i]-1] != colors[bridges[i+1]-1]) {
                answ++;
                } } std::cout << answ/2;
}
