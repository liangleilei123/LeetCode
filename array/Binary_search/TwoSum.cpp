#include<iostream>
#include<vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        int temp = nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); ++i)
        {
            
            int rel = target - nums[i];
            nums[nums.size() - 1] = rel;

            

            for (int j = 0;; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (nums[j] == nums[nums.size() - 1])
                {
                    if (j != nums.size() - 1)
                        return { i,j };
                    else if (temp == nums[j])
                        return { i,j };
                    else
                        break;
                }

            }
        }
        return { 0,0 };
    }
};


int main()
{
    Solution A;
    std::vector<int> vec{ -1,-2,-3,-4,-5 };
    int target = -8;
    std::vector<int> ret_vec = A.twoSum(vec, target);
    std::cout<< '[' << ret_vec[0] << ',' << ret_vec[1] <<']' << std::endl;
}
