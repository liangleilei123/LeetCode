class Solution {
public:
//两指针，一前一后，指向的值不相等，[left+1]=[right]，right++；相等，right右移。right到数组末尾结束
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left = 0;
        int right = left+1;
        while(right<nums.size())
        {
            if(nums[left] != nums[right])
                nums[++left] = nums[right++];
            else          
                ++right;
        }
        return left+1;
    }
};