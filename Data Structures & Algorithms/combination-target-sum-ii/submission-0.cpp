class Solution {
public:

vector<vector<int>>ans;
void backtrack(vector<int>& candidates,int start, int target,vector<int>& curr){
    if(target==0){
        ans.push_back(curr);
        return;
    }

    for(int i=start;i<candidates.size();i++){
        if(i >start && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        curr.push_back(candidates[i]);
        backtrack(candidates,i+1,target-candidates[i],curr);
        curr.pop_back();

    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        backtrack(candidates,0,target,curr);
        return ans;
    }
};
