#include <iostream>
#include <vector>

int main() {
    int numberOfDays;
    std::cin >> numberOfDays;
    std::vector <int> prices (numberOfDays, 0);

    for (int i = 0; i < numberOfDays; ++i) {
        std::cin >> prices[i];
    }
    
    for (int i = 0; i < numberOfDays; ++i) {
        int max = prices[i]*(i + 1);
        for (int j = 0; j < i; ++j) {
            int sum = prices[j] + prices[i]*(i-j);
            if (max < sum) max = sum;
        }
        prices[i] = max;
    }
    std::cout << prices[numberOfDays - 1];
}
