//用空间复杂度为O(1)方法移除数组元素

//思路，双指针，right指针遍历数组，left指向下一个要赋值的位置，赋的值是不等于val的值，由right遍历得到

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

//双指针优化，左指针指向数组首地址，右指针指向数组末尾，
// ①左指针指向的值不等于val，左指针往右移一位
//②左指针指向的值等于val，就把右指针指向的值赋值给左指针指向的位置，右指针左移一位
//③再判断左指针，跳到①

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