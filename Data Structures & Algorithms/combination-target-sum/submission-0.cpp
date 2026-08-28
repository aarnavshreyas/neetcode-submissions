class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;

    void dfs(vector<int>& nums, int target, int i) {

        // Target reached
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        // No more numbers or target becomes negative
        if (i >= nums.size() || target < 0) {
            return;
        }

        // Choice 1: Take nums[i]
        combination.push_back(nums[i]);

        // Same i -> we can use nums[i] again
        dfs(nums, target - nums[i], i);

        // Undo the choice
        combination.pop_back();

        // Choice 2: Skip nums[i]
        dfs(nums, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return result;
    }
};