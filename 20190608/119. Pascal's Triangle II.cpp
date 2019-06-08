// Pascal三角 给出第K行的值 用O(K)空间复杂度

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        int i = 0;
        while(i <= rowIndex)
        {
            res[0] = 1;
            res[i] = 1;
            int tmp = 1;
            
            for(int j = 1; j < i; j++)
            {
                int prev = res[j];
                res[j] = tmp + res[j];
                tmp = prev;
            }
            
            i++;
        }
       
        return res;
        
    }
};