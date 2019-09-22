#include <iostream>

#include <math.h>

long long getCountOdd(long long level) {
  long long mid = (level + 1) / 2;
  long long sum = 3, difference = 7, term = 3;
  for (int i = mid + 1; i < level; ++i) {
    term += difference;
    sum += term;
    difference += 4;
  }
  return sum;
}
long long getCountEven(long long level) {
  long long mid = level / 2;
  long long sum = 1, difference = 5, term = 1;
  for (int i = mid + 1; i < level; ++i) {
    term += difference;
    sum += term;
    difference += 4;
  }
  return sum;
}
long long getCount2(long long int level) {
  if (level % 2 == 0) {
    return getCountEven(level);
  }
  if (level % 2 != 0) {
    return getCountOdd(level);
  }
}
long long getCount1(long long int level) {
  long long sum = 0;
  long long term, newValue = 0;
  for (int i = 0; i < level; ++i) {
    term = i + 1;
    newValue += term;
    sum += newValue;
  }
  return sum;
}
int main() {
  int test;
  std::cin >> test;
  for (int _ = 0; _ < test; _++) {
    long long int level;
    std::cin >> level;
    if (level == 1) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << getCount1(level) + getCount2(level) << std::endl;
    }
  }
}