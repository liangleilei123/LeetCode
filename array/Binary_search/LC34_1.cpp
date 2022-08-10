//思路，用二分查找，找到一个目标值后，在目标值的前后查找，在多数情况下效率较高，但是在
//极端条件（一个数组全是同样的值时）效率较低，变成O(n)
#include<vector>


class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        int rel_left = 0; int rel_rig = 0;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {

                for (rel_left = mid - 1; rel_left >= 0 && nums[rel_left] == target; --rel_left);

                for (rel_rig = mid + 1; rel_rig <= right && nums[rel_rig] == target; ++rel_rig);

                return { rel_left + 1,rel_rig - 1 };
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return { -1,-1 };
    }
};