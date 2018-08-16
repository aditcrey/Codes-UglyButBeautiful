//https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int curSum = INT_MAX, diff = INT_MAX, ans = INT_MAX;
        
        for(int i=0;i<n-2;i++){
            int l = i+1,r=n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                // cout<<"ans: "<<ans<<" i: "<<i<<" l: "<<l<<" r: "<<r<<endl;
                // cout<<" diff: "<<diff<<endl;
                
                if(diff >= abs(target-sum)){
                    diff = abs(target-sum);
                    ans = sum;
                }
                
                if(sum==target) return target;
                
                if(sum <= target) l++;
                else if (sum > target) r--;
                else break;

            }
        }
        
        return ans;
        
    }
};
