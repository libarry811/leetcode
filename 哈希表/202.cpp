/202快乐数
class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_set <int> num_set;
        int result=0;
        int num;
        while(n!=1)
        {
            while(n!=0)
            {
                num=n%10;
                n=n/10;
                result=result+num*num;
            }
            if(num_set.find(result)==num_set.end())
            {
                num_set.insert(result);
            }
            else
            {
                return false;
            }
            n=result;
            result=0;

        }
        return true;
    }
};
