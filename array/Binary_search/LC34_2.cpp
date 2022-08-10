//˼·�������ζ��ֲ��ң�һ�β���С��Ŀ��ֵ�����õ���߽磬һ�β��Ҵ���Ŀ��ֵ�����õ��б߽磬�õ���Χ

#include<vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int l_border = GetLeftBorder(nums, target);
        int r_border = GetRightBorder(nums, target);

        //��һ�������target���ڻ�С�����鷶Χ
        if(l_border == -2||r_border == -2) return { -1,-1 };
       //�����������target��������
        if (r_border - l_border > 1) return { l_border + 1,r_border - 1 };

        //�ڶ��������target�����鷶Χ�ڣ����ǲ��������У���ʱ��Getborder�����ķ���ֵ����-2,
        //��Ԫ��Ҫ�����λ��,�������Ҳ�߽�ָ����һ���ط�
        return { -1,-1 };
    }

private:
    //�ҵ��ұ߽�
    int GetRightBorder(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int RightBorder = -2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)     //�ҵ�����target�����������������
            {
                right = mid - 1;
            }
            else                        //�ҵ�С�ڵ���target���������ұ��ң������ұ߽�
            {
                left = mid + 1;
                RightBorder = left;
            }
        }
        return RightBorder;
    }

    //�ҵ���߽�
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