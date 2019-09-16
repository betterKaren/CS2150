// Yu Du, yd2am
// xToN.cpp
// 09/06/2019

#include <iostream>
using namespace std;

int xton (int x, int n) {
  if (n == 0){
    return 1;
  }
  return x * xton (x, n-1);
}

int main () {
  cout << "Hi! Please input x and n" << endl;
  int x, n, ans;
  cin >> x;
  cin >> n;
  ans = xton (x, n);
  cout << x << "^" << n << "=" << ans << endl;
  return 0;
}

