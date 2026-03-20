class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int maxEl = *max_element(nums.begin(),nums.end())  ;
      int maxLen=1; //bitwise and can only decrease the val so return maxEl length
      int count=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==maxEl){
            count++;
            maxLen=max(maxLen,count);
      }
      else count=0;
      }
      return maxLen;
    }
};