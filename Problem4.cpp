// Problem: Pair of single numbers missing
//  Time Complexity : O(n)
//  Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We use rolling hash to calculate the hash and then if we see a repeated
// hash, we append to result
// 2. We have a map for the possible characters in the string
// 3. if window becomes > 10, we subtract the contribution of 1st character from
// the hash and i >= 9, we check if the current hash is present, if yes then we
// add the substr to our set

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<long long> se;
    unordered_set<string> ans;
    int n = (int)s.size();
    int MOD = 1e9 + 7;
    long long maxp = pow(4, 10);
    long long phash = 0;
    unordered_map<char, int> u = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    for (int i = 0; i < n; i++) {
      int in = u[s[i]];
      phash = (phash * 4 + in) % MOD;
      if (i >= 10) {
        int out = u[s[i - 10]];
        phash = ((phash - (maxp * out) % MOD + MOD)) % MOD;
      }
      if (i >= 9) {
        if (se.count(phash) > 0) {
          ans.insert(s.substr(i - 9, 10));
        }
      }
      se.insert(phash);
    }

    return vector<string>(begin(ans), end(ans));
  }
};
