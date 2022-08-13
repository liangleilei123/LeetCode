#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        //利用他非递减序列的特点，加上双指针，用空间换时间
        //先把原数组的正负数分界，再平方，设计双指针，各指向一个数组，比较大小后存入原数组
        std::vector<int> vec_zheng;
        std::vector<int> vec_fu;
        int z = 0, f = 0;   //z和f可能是负数
        int j = 0;      //存结果的指针
        for (std::vector<int>::size_type i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                vec_fu.push_back(nums[i] * nums[i]);      //数组中的值是从大到小的,
            else
                vec_zheng.push_back(nums[i] * nums[i]);   //数组中的值是从小到大的
            //循环结束后f,z表示的是数组长度
        }
        f = vec_fu.size() -1;   //保证值的遍历从小到大
        while (f >= 0 && z < vec_zheng.size())
        {
            //挨个比较两值
            if (vec_fu[f] >= vec_zheng[z])
            {
                //小的先存
                nums[j] = vec_zheng[z];
                ++z;        //存完之后往大的值移动
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