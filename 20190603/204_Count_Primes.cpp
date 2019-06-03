class Solution {
public:
    int countPrimes(int n) {
        // version3
        if(n <3) return 0;
        
        vector<bool> isprime(n, true);
        
        int count = 1;
        
        for(int i = 3; i < n; i += 2)
        {
            if (isprime[i] == true)
            {
                count ++;
                for(int j = 2; i * j < n; j++)
                {
                    isprime[i*j] = false;
                }
            }
                
        }
        return count;





        // version2        
        // vector<bool> isprime(n, true);
        // int count = 0;
        
        // for(int i = 2; i < n; i++)
        // {
        //     if (isprime[i] == true)
        //     {
        //         count ++;
        //         for(int j = 2; i * j < n; j++)
        //         {
        //             isprime[i*j] = false;
        //         }
        //     }
                
        // }
        // return count;



        // version1
        // if (n <= 2 ) return 0;       
        // int res = 1;
        // for (int i = 3; i < n; i += 2)
        // {
        //     int prime = 1;
        //     for(int j = 3; j <= sqrt(i); j ++)
        //     {
        //         if (i  % j == 0)
        //         {
        //             prime = 0;
        //             break;
        //         }     
        //     }
        //     if(prime)
        //         res += 1;
        // }
        // return res;        
    }
};