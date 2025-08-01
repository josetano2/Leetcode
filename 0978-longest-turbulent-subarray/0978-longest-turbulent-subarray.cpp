class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        // -1 = not assigned
        // 0 = <
        // 1 = >
        if (arr.size() == 1)
            return 1;

        int swtch = arr[0] < arr[1] ? 0 : 1, counter = 1, ans = -1;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (swtch == 0) {
                if (arr[i] > arr[i + 1]) {
                    counter = 1;
                    i--;
                } else if (arr[i] < arr[i + 1]) {
                    counter++;
                } else {
                    counter = 1;
                }
                swtch = 1;
            } else {
                if (arr[i] < arr[i + 1]) {
                    counter = 1;
                    i--;
                } else if (arr[i] > arr[i + 1]) {
                    counter++;
                } else {
                    counter = 1;
                }
                swtch = 0;
            }

            cout << counter << " " << arr[i] << " " << arr[i + 1] << endl;
            ans = max(ans, counter);
        }

        return ans;
    }
};