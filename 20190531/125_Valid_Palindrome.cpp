class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            while (isalnum(s[i]) == false && i < j) i++; // 如果输入仅一个非字母数字的字符 越界,so: with i<j
            while (isalnum(s[j]) == false && i < j) j--;
            if (toupper(s[i]) != toupper(s[j])) return false;
        }
         return true;
    }
};Valid Palindrome