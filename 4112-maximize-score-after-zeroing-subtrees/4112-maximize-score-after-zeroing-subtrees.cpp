class Solution {
public:
    vector<int> dp;
void dfs(int node,vector<int>& score, vector<int>& op, vector<vector<int>> &adj){
    if(adj[node].empty()){
        dp[node] = score[node];
        return;
    }
    int sum = 0;
    int minn = 2e9;
    for(auto it : adj[node]){
        dfs(it, score, op, adj);
        sum += dp[it];
        minn = min(minn, dp[it]);
    }
    if(op[node] == 0) dp[node] = score[node] + sum - min(0, minn);
    else dp[node] = score[node] + sum - minn;
}
    
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        dp.resize(n, 0);
        dfs(0, score, op, adj);
        return dp[0];
    }
};