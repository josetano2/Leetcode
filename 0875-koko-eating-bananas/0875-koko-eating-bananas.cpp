class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int len = piles.size();

        int max = -1, min = INT_MAX;
        for(auto x : piles){
            if(x < min){
                min = x;
            }
            if(x > max){
                max = x;
            }
        }

        int left = 1, right = max;

        while(left <= right){

            int mid = left + (right - left) / 2;
            long long int tot = 0;

            for(auto x : piles){
                tot += ceil(x / (double) mid);
            }

            cout << endl;

            cout << "Total Hours: " << tot << endl;
            cout << "Left: " << left << endl;
            cout << "Right: " << right << endl;
            cout << "Middle: " << mid << endl;
            cout << endl;

            if(tot <= h){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};