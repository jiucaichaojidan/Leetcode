class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size()) swap(a, b);
        while(b.size() < a.size()) b += '0';
        int add = 0;
        for(int i = 0; i < a.size(); i++)
        {
            int sum = add + a[i] - '0' + b[i] - '0';
            b[i] = sum % 2 + '0';
            add = sum / 2;
        }
        if(add != 0)
            b = b + '1';
        reverse(b.begin(), b.end());
        return b;
    }
};