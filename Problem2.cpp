// Problem: Single Number
//  Time Complexity : O(n)
//  Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We start with number 0 and keep xoring each num in the array
// 2. 3^3 = 0 so repeated numbers cancel out and we are only left with the
// unique single number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int x = 0;
    for (int num : nums) {
      x ^= num;
    }
    return x;
  }
};
