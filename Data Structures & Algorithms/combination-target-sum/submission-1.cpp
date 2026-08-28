class Solution{
    public:
    vector<vector<int>>combinationSum(vector<int>&nums,int target){
        vector<vector<int>>result;
        vector<int>current;
        sort(nums.begin(),nums.end());
        function<void(int,int)>dfs=[&](int start,int target){
            if(target==0){
                result.push_back(current);
                return;
            }
            for(int i=start;i<nums.size();i++){
                if(nums[i]>target)break;
                current.push_back(nums[i]);
                dfs(i,target-nums[i]);
                current.pop_back();
            }
            };
            dfs(0,target);
            return result;
    }
};