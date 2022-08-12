class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//只把不为0的值放在数组前面，
        int left = 0;
        int right = 0;
        int len = nums.size();
        while(right < len)
        {
            if(nums[right])
                nums[left++] =nums[right];
            ++right;
        }
        //很巧妙，此时left指向的刚好是数组结尾0开始的位置
        for(;left < len;++left)     
        {
            nums[left] = 0;
        }
    }
};