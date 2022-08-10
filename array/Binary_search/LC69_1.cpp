//求x的平方根
//思路：用二分查找法。条件k^2 <= x,取k的最大值
class Solution {
public:
    int mySqrt(int x) {
        int l = 0,r = x;
        int k = 0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if((long long)mid*mid > x)
                r = mid -1;
            else
            {
                k = mid;
                l = mid +1;
            }
        }
        return k;
    }
};