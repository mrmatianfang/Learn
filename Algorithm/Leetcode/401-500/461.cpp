class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x^y,ret = 0;
        while(s)
        {   
            s&=s-1;
            ret+=1;
        }
        return ret;
    }
};
