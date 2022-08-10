//#include<iostream>
//#include<vector>
//
//±©Á¦½â
// 
//class Solution {
//public:
//    std::vector<int> twoSum(std::vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            int n = target - nums[i];
//            for (int j = 0; j < nums.size(); ++j)
//            {
//                if (i == j)
//                {
//                    continue;
//                }
//                if (nums[j] == n)
//                {
//                    return { i,j };
//                }
//            }
//        }
//
//    }
//};
//
//int main()
//{
//    Solution A;
//    std::vector<int> vec{ 2,7,11,15 };
//    int target = 9;
//    std::vector<int> ret_vec = A.twoSum(vec, target);
//    std::cout << '[' << ret_vec[0] << ',' << ret_vec[1] << ']' << std::endl;
//}
