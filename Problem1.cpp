// Problem: Divide two integers
//  Time Complexity : O(logn)
//  Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We first cast both divisor and dividend to long
// 2. We start a while loop til dividend >= divisor and calculate no of shifts
// required
// 3. Add power of 2 shifts to result and reduce the dividend by the (divs <<
// shifts)
// 4. After handling edge cases return the ans

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;
    if (divisor == 1)
      return dividend;
    long divd = abs((long)dividend);
    long divs = abs((long)divisor);
    long res = 0;
    while (divd >= divs) {
      int shifts = 0;
      while (divd >= (divs << shifts)) {
        shifts++;
      }
      // get back
      shifts--;
      res += (1 << shifts);
      divd -= (divs << shifts);
    }

    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
      return (int)res;
    return (int)-res;
  }
};
