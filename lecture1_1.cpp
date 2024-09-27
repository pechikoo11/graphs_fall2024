#include <iostream>

int main() {
    int N, check, answ = 0;
    std::cin >> N;
    for (int s = 0; s < N; s += 1) {
        for (int i = 0; i < N; i += 1){
        std::cin >> check; 
        if (check==1) answ++;} 
    } std::cout << answ/2 << std::endl;
}
