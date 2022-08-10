#include<iostream>
//有效的完全平方数

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            //强制类型转换,把mid转换成long long类型才进行*运算，最终得到long long 类型的结果传递到等号左边
            long long mid_2 = (long long)mid * mid;     
            //long long mid_2 = mid * mid;              //自动类型转换，会造成有符号整形溢出
            if (mid_2 > num)
            //if((long long)mid*mid > num)              //编译器自动创建了一个临时long long对象保存结果
                r = mid - 1;
            else if (mid_2 < num)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution A;
    std::cout << A.isPerfectSquare(2000105819) << std::endl;
}