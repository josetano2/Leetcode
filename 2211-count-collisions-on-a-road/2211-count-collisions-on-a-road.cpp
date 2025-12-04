class Solution {
public:
    int countCollisions(string directions) {

        int l = 0, r = directions.size() - 1;
        while(l < directions.size() && directions[l] == 'L') l++;
        while(r >= 0 && directions[r] == 'R') r--;

        int tot = 0;
        for(int i = l; i <= r; i++) if(directions[i] != 'S') tot++;
    
        return tot;
    }
};


// Redundant Approach
// class Solution {
// public:
//     int countCollisions(string directions) {

//         unordered_map<char, int> card;
//         card['R'] = 1;
//         card['L'] = -1;
//         card['S'] = 0;

//         int tot = 0;
//         for (int i = 0; i < directions.size() - 1; i++) {

//             // R + L = 1 - 1;
//             int curr = card[directions[i]] + card[directions[i + 1]];
//             if (curr == 0 && directions[i] == 'R' && directions[i + 1] == 'L') {
//                 tot += 2;
//                 directions[i] = 'S';
//                 directions[i + 1] = 'S';
//                 int temp = i - 1;
//                 while(temp >= 0 && directions[temp] == 'R') {
//                     tot += 1;
//                     directions[temp] = 'S';
//                     temp--;
//                 }
//             } else if (curr == 1 && directions[i] == 'R') {
//                 tot += 1;
//                 directions[i] = 'S';

//                 int temp = i - 1;
//                 while(temp >= 0 && directions[temp] == 'R') {
//                     tot += 1;
//                     directions[temp] = 'S';
//                     temp--;
//                 }
//             } else if (curr == -1 && directions[i] == 'S') {
//                 tot += 1;
//                 directions[i + 1] = 'S';
//             }
//         }

//         return tot;
//     }
// };