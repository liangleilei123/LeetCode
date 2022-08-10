//˼·���ö��ֲ��ң��ҵ�һ��Ŀ��ֵ����Ŀ��ֵ��ǰ����ң��ڶ��������Ч�ʽϸߣ�������
//����������һ������ȫ��ͬ����ֵʱ��Ч�ʽϵͣ����O(n)
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