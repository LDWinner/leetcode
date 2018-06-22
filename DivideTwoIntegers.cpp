class Solution {
public:
    int divide(int dividend, int divisor) {
        int8_t flag1 = 0;
        int8_t flag2 = 0;
        if(dividend < 0)
        {
            dividend = -dividend;
            flag1 = 1;
        }
        if(divisor < 0)
        {
            divisor = -divisor;
            flag2 = 1;
        }

        int tmp = divisor;
        int result = 0;

        while(tmp <= dividend)
        {
            tmp += divisor;
            ++result;
        }

        if(flag1 ^ flag2)
        {
            result = -result;
        }
        return result;
    }
};
