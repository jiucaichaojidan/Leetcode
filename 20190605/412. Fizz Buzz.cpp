class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> res;
        
        for(int i = 1, fuzz = 0, buzz = 0; i <= n; i++)
        {
            fuzz++;
            buzz++;
            if(fuzz == 3 && buzz == 5)
            {
                res.push_back("FizzBuzz");
                fuzz = 0;
                buzz = 0;
            }
            else if(fuzz == 3)
            {
                res.push_back("Fizz");
                fuzz = 0;
            }
            else if(buzz == 5)
            {
                res.push_back("Buzz");
                buzz = 0;
            }
            else
                res.push_back(to_string(i));
        }
        
        return res;

        
    }
};