class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;

        long st = 1, en = x;
        while(st <= en){
            int mid = (st + en) / 2;
            if(mid > x / mid)
                en = mid - 1;
            else if(mid < x / mid)
                st = mid + 1;
            else return mid;
        }

        return en;
    }
};