// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int row = 0;
        int p = 1;
        for(auto c:s)
        {
            v[row] += c;
            if(row == numRows - 1)
                p = -1;
            if(row == 0)
                p = 1;
            row += p;
        }
        string res = "";
        for(auto str:v)
        {
            res += str;
        }
        return res;
    }
};