class Ride{
public:

    int st, d;

    Ride(int st, int d){
        this->st = st;
        this->d = d;
    }
};

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int nl = landStartTime.size(), nw = waterStartTime.size();
        vector<Ride> land, water;

        for(int i = 0; i < nl; i++) land.push_back(Ride(landStartTime[i], landDuration[i]));
        for(int i = 0; i < nw; i++) water.push_back(Ride(waterStartTime[i], waterDuration[i]));


        sort(land.begin(), land.end(), [](const Ride& a, const Ride& b){
            return a.st < b.st;
        });

        sort(water.begin(), water.end(), [](const Ride& a, const Ride& b){
            return a.st < b.st;
        });

        vector<int> pfixL(nl, INT_MAX);
        vector<int> sfixL(nl, INT_MAX);
        vector<int> pfixW(nw, INT_MAX);
        vector<int> sfixW(nw, INT_MAX);

        pfixL[0] = land[0].d;
        sfixL[nl - 1] = land[nl - 1].st + land[nl - 1].d;
        pfixW[0] = water[0].d;
        sfixW[nw - 1] = water[nw - 1].st + water[nw - 1].d;

        for(int i = 1; i < nl; i++) {
            pfixL[i] = min(land[i].d, pfixL[i - 1]);
            sfixL[nl - i - 1] = min(land[nl - i - 1].st + land[nl - i - 1].d, sfixL[nl - i]);
        }

        for(int i = 1; i < nw; i++) {
            pfixW[i] = min(water[i].d, pfixW[i - 1]);
            sfixW[nw - i - 1] = min(water[nw - i - 1].st + water[nw - i - 1].d, sfixW[nw - i]);
        }

        int ans = INT_MAX;
        for(int i = 0; i < nl; i++) {
            int t = land[i].st + land[i].d;

            auto it = lower_bound(water.begin(), water.end(), t, [](const Ride& r, int value) {
                    return r.st < value;
                }
            );

            int pos = it - water.begin();

            if(pos == nw) ans = min(ans, t + pfixW[pos - 1]);
            else if(pos == 0) ans = min(ans, sfixW[pos]);
            else ans = min({ans, t + pfixW[pos - 1], sfixW[pos]});
        }

        for(int i = 0; i < nw; i++) {
            int t = water[i].st + water[i].d;

            auto it = lower_bound(land.begin(), land.end(), t, [](const Ride& r, int value) {
                    return r.st < value;
                }
            );

            int pos = it - land.begin();

            if(pos == nl) ans = min(ans, t + pfixL[pos - 1]);
            else if(pos == 0) ans = min(ans, sfixL[pos]);
            else ans = min({ans, t + pfixL[pos - 1], sfixL[pos]});
        }
        
        return ans;
    }
};