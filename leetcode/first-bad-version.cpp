#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int version){
    return true;
}

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while(l<=r){
      int mid = l + (r-l)/2;
      if(isBadVersion(mid)) r = mid - 1;
      else l = mid + 1;
    }
    return l;
  }
};

int main() {
  // take an vector of number
  vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
  vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
  vector<vector<int>> matrix = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12}
  };

  Solution s;

  // int ans = s.findMedianSortedArrays(nums, nums);
  // cout << ans << endl;

  // vector<int> ans = s.twoSum(nums, 9);
  // for(int i = 0; i < ans.size(); i++){
  //     cout << ans[i] << " ";
  // }
  // cout << endl;

  return 0;
}