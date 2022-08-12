#include<iostream>
#include<string>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        //双指针，一个指针指向s，从后往前遍历。当碰到#时，记录#的数量，当碰到不是#时，先判断记录的#的数量是否为0
        //如果不为0，模拟删除，即指针往前移动，如果为0，跳出循环，用同样的方法遍历t。得到两个不为#的值，比较两值
        //不相等返回false，相等继续查找，直到数组遍历结束，如果一个数组先遍历结束，返回false.如果两个数组同时结束，返回true
        int s_backnum = 0;
        int t_backnum = 0;
        int s_loc = s.size() - 1;
        int t_loc = t.size() - 1;
        while (1)
        {
            while (s_loc >= 0)
            {
                if (s[s_loc] == '#')
                    ++s_backnum;
                else
                {
                    if (s_backnum > 0)
                        --s_backnum;
                    else
                        break;
                }
                --s_loc;
            }
            while (t_loc >= 0)
            {
                if (t[t_loc] == '#')
                    ++t_backnum;   
                else
                {
                    if (t_backnum > 0)
                        --t_backnum;
                    else
                        break;
                }
                --t_loc;

            }
            if (s_loc < 0 || t_loc < 0)
                break;
            
            if (s[s_loc] != t[t_loc])
                return false;
            --s_loc;
            --t_loc;
        }
        if (s_loc == -1 && t_loc == -1) return true;
        return false;
    }
};


int main()
{
    Solution A;
    std::cout<< A.backspaceCompare("ab#c", "ad#c");
}