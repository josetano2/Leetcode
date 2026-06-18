class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = minutes * 6.0, h = (hour % 12) * 30.0 + minutes * 0.5, diff = abs(h - m);
        return min(diff, 360 - diff);
    }
};