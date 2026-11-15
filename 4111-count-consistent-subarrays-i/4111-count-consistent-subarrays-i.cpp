class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            int minn = nums[i];
            int a = nums[i];
            for(int j = i; j < nums.size(); j++){
                minn = min(minn, nums[j]);
                a = a & nums [j];
                if(a == minn) cnt++;
            }
        }
        return cnt;
    }
};