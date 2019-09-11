#include <iostream>

using namespace std;

bool isAP(int number1, int number2, int number3)
{
  return number1 + number3 == 2 * number2;
}

bool isGP(int number1, int number2, int number3)
{
  return number1 * number3 == number2 * number2;
}

int main(int argc, char const *argv[])
{
  int number1, number2, number3;
  while (true)
  {
    cin >> number1 >> number2 >> number3;
    if (number1 == 0 && number2 == 0 && number3 == 0)
      break;
    if (isAP(number1, number2, number3))
      cout << "AP " << number3 + number2 - number1 << endl;
    if (isGP(number1, number2, number3))
      cout << "GP " << number3 * number2 / number1 << endl;
  }
  return 0;
}