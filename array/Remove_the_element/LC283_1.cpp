class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//还是用双指针，左指针指向的等于0,右指针不为0，[left]=[right],right+1;
//左右指针指向的都等于0，右指针右移
//不等于，左右指针均右移
        int left = 0;
        int right = 1;
        int len = nums.size();
        while(right < len)
        {
            if(nums[left] == 0)
            //交换左右值
            {
                if(nums[right] != 0)
                {
                    nums[left++] = nums[right];
                    nums[right] = 0;
                }
                ++right;    
            }
            else
            {
                ++left;
                ++right;
            }
            
        }

    }
};