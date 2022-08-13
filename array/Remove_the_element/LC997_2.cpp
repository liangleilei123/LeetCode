//由于是非递减序列，负数越小，其平方越大，正数越大，其平方越大。
//正好在最左边和最右边，由此可以双指针一左一右遍历，取值并比较，放入新的数组中

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);        //由于值是从大到小往数组中放，因此要先初始化
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};