//Combination Sum if elements arent repeated
class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,vector<vector<int>> &ds,vector<int> output,int sum,int n){
        if(i==n){
           if(sum == target){
                ds.push_back(output);
               
           }
            return;
        }
        //include
        sum+=candidates[i];
        output.push_back(candidates[i]);
        solve(i+1,candidates,target,ds,output,sum,n);
        sum-=candidates[i];
        output.pop_back();
        //exclude
        solve(i+1,candidates,target,ds,output,sum,n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ds;
        vector<int> output;
        int n = candidates.size();
        int sum = 0;
        solve(0,candidates,target,ds,output,sum,n);
        return ds;
    }
};