/**
 * problem : https://blog.naver.com/withham1/221252023073
 * time complexity : O(N)
 */
 
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    int ans = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]==nums[i])
            continue;
        nums[ans++] = nums[i];
    }
    return ans;
}
