class Solution {
public:
    int countCollisions(string directions) {

        unordered_map<char, int> card;
        card['R'] = 1;
        card['L'] = -1;
        card['S'] = 0;

        int tot = 0;
        for (int i = 0; i < directions.size() - 1; i++) {

            // R + L = 1 - 1;
            int curr = card[directions[i]] + card[directions[i + 1]];
            if (curr == 0 && directions[i] == 'R' && directions[i + 1] == 'L') {
                cout << i << " ";
                tot += 2;
                directions[i] = 'S';
                directions[i + 1] = 'S';
                int temp = i - 1;
                while(temp >= 0 && directions[temp] == 'R') {
                    cout << temp << " ";
                    tot += 1;
                    directions[temp] = 'S';
                    temp--;
                }
            } else if (curr == 1 && directions[i] == 'R') {
                cout << i << " ";
                tot += 1;
                directions[i] = 'S';

                int temp = i - 1;
                while(temp >= 0 && directions[temp] == 'R') {
                    cout << temp << " ";
                    tot += 1;
                    directions[temp] = 'S';
                    temp--;
                }
            } else if (curr == -1 && directions[i] == 'S') {
                cout << i << " ";
                tot += 1;
                directions[i + 1] = 'S';
            }
        }

        return tot;
    }
};