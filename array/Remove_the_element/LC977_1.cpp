#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        //�������ǵݼ����е��ص㣬����˫ָ�룬�ÿռ任ʱ��
        //�Ȱ�ԭ������������ֽ磬��ƽ�������˫ָ�룬��ָ��һ�����飬�Ƚϴ�С�����ԭ����
        std::vector<int> vec_zheng;
        std::vector<int> vec_fu;
        int z = 0, f = 0;   //z��f�����Ǹ���
        int j = 0;      //������ָ��
        for (std::vector<int>::size_type i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                vec_fu.push_back(nums[i] * nums[i]);      //�����е�ֵ�ǴӴ�С��,
            else
                vec_zheng.push_back(nums[i] * nums[i]);   //�����е�ֵ�Ǵ�С�����
            //ѭ��������f,z��ʾ�������鳤��
        }
        f = vec_fu.size() -1;   //��ֵ֤�ı�����С����
        while (f >= 0 && z < vec_zheng.size())
        {
            //�����Ƚ���ֵ
            if (vec_fu[f] >= vec_zheng[z])
            {
                //С���ȴ�
                nums[j] = vec_zheng[z];
                ++z;        //����֮�������ֵ�ƶ�
            }
            else
            {
                nums[j] = vec_fu[f];
                --f;
            }
            ++j;
        }
        if (f < 0)
            while (z < vec_zheng.size())
                nums[j++] = vec_zheng[z++];
        else
            while (f >= 0)
                nums[j++] = vec_fu[f--];

        return nums;
    }
};

int main()
{
    Solution A;
    std::vector<int> vec_nums{ -4,-1,0,3,10 };
    auto vec_rel = A.sortedSquares(vec_nums);
    for (auto i : vec_rel)
    {
        std::cout << i << "   ";
    }
}