#include <iostream>

int main() {
  int N = 0;
  long long first = 0, second = 0;
  std::cin >> N >> first >> second;
  while (first != second) {
    if (first > second) {
      first /= 2;
    } else {
      second /= 2;
    } } std::cout << first;
}
