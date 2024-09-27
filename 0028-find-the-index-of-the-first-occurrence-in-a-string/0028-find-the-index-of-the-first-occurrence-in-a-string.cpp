
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay = haystack.size(), lenNeedle = needle.size();

        if(lenHay == 0) return 0;

        for(int i = 0; i <= lenHay - lenNeedle; i++){
            int j = 0; 

            // Kondisi 1 -> buat cek j sama panjang needle
            // kondisi 2 -> cek dari i sekarang sama j ke depannya
            while(j < lenNeedle && haystack[i + j] == needle[j]) j++;

            // kalo ketemu pasti j ama lenNeedle sama
            if(j == lenNeedle) return i;
            
        }

        return -1;
    }
};