//�����Ƿǵݼ����У�����ԽС����ƽ��Խ������Խ����ƽ��Խ��
//����������ߺ����ұߣ��ɴ˿���˫ָ��һ��һ�ұ�����ȡֵ���Ƚϣ������µ�������

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);        //����ֵ�ǴӴ�С�������зţ����Ҫ�ȳ�ʼ��
        for (int i = 0, j = A.size() - 1; i <= j;) { // ע������Ҫi <= j����Ϊ���Ҫ��������Ԫ��
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