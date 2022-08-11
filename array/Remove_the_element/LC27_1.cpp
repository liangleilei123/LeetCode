//�ÿռ临�Ӷ�ΪO(1)�����Ƴ�����Ԫ��

//˼·��˫ָ�룬rightָ��������飬leftָ����һ��Ҫ��ֵ��λ�ã�����ֵ�ǲ�����val��ֵ����right�����õ�

#include<iostream>
#include<vector>

//class Solution {
//public:
//    int removeElement(std::vector<int>& nums, int val) {
//        int left = 0;
//        int n = nums.size();
//        for (int right = 0; right < n; ++right)
//        {
//            if (nums[right] != val)
//                nums[left++] = nums[right];
//        }
//        return left;
//    }
//};

//˫ָ���Ż�����ָ��ָ�������׵�ַ����ָ��ָ������ĩβ��
// ����ָ��ָ���ֵ������val����ָ��������һλ
//����ָ��ָ���ֵ����val���Ͱ���ָ��ָ���ֵ��ֵ����ָ��ָ���λ�ã���ָ������һλ
//�����ж���ָ�룬������

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] != val)
                ++left;
            else
            {
                nums[left] = nums[right];
                --right;
            }

        }
        
        return left;
    }
};


int main()
{
    Solution A;
    std::vector<int> vec_int{ 3,2,2,3 };
    std::cout << A.removeElement(vec_int, 3) <<std::endl;

    for (auto i : vec_int)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}