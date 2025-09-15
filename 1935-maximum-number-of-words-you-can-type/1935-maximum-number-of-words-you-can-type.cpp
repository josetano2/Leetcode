class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> uSet;

        for(auto x : brokenLetters) uSet.insert(x);

        int counter = 0;
        bool isValid = true;
        for(auto x : text) {
            if(!isValid) {
                cout << x << endl;
                if(x == ' ') isValid = true;
                continue;
            }

            if(x == ' ') {
                counter++;
                continue;
            }
            
            if(uSet.find(x) != uSet.end()) isValid = false;
        }

        return isValid ? counter + 1 : counter;
        
    }
};