#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
  int n;
  cin >> n;
  while (n != 0)
  {
    stack<int> cars;
    int array[n];
    int i = 0, j;
    bool ans = true;
    while (i < n)
    {
      cin >> array[i];
      i++;
    }

    i = 0, j = 1;
    while (i < n)
    {
      // 1 2 3
      if (array[i] == j)
      {
        j++;
        i++;
      }

      else if (!cars.empty() && cars.top() == j)
      {
        j++;
        cars.pop();
      }
      else
      {
        if (!cars.empty() && array[i] > cars.top())
        {
          ans = false;
          break;
        }
        else
          cars.push(array[i]);
        i++;
      }
    }
    if (ans)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
    cin >> n;
  }
  return 0;
}

