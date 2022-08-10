//思路：用两次二分查找，一次查找小于目标值的数得到左边界，一次查找大于目标值的数得到有边界，得到范围

#include<vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int l_border = GetLeftBorder(nums, target);
        int r_border = GetRightBorder(nums, target);

        //第一种情况，target大于或小于数组范围
        if(l_border == -2||r_border == -2) return { -1,-1 };
       //第三种情况，target在数组中
        if (r_border - l_border > 1) return { l_border + 1,r_border - 1 };

        //第二种情况，target在数组范围内，但是不在数组中，这时候Getborder函数的返回值不是-2,
        //是元素要插入的位置,而左侧和右侧边界指的是一个地方
        return { -1,-1 };
    }

private:
    //找到右边界
    int GetRightBorder(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int RightBorder = -2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)     //找到大于target的数，继续往左边找
            {
                right = mid - 1;
            }
            else                        //找到小于等于target的数，往右边找，设置右边界
            {
                left = mid + 1;
                RightBorder = left;
            }
        }
        return RightBorder;
    }

    //找到左边界
    int GetLeftBorder(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
                leftBorder = right;
            }
            else
            {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
};