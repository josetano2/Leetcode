class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l = 0, r = colors.size() - 1;

        while(l < r) {
            if(colors[l] != colors[r]) return abs(r - l);
            
            int tL = l, tR = r;
            while(tL < tR && colors[l] == colors[tL]) tL++;
            while(tL < tR && colors[r] == colors[tR]) tR--;
            
            if(r - tR > tL - l) l = tL;
            else r = tR;
        }
        
        return -1;
    }
};