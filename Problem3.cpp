// Problem: Pair of single numbers missing
//  Time Complexity : O(n)
//  Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We start with number 0 and keep xoring each num in the array
// 2. Next, we calculate the lsb of xor'ed number
// 3. We then check if num & lsb gives us zero it goes to one group1 otherwise
// group2, return both at the end
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    long long x = 0;
    for (int num : nums) {
      x ^= num;
    }
    int lsb = x & -x;
    int group1 = 0;
    int group2 = 0;
    for (int num : nums) {
      if ((num & lsb) == 0) {
        group1 ^= num;
      } else {
        group2 ^= num;
      }
    }
    return {group1, group2};
  }
};
