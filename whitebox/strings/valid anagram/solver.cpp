#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline bool isAnagram(string_view s, string_view t) {

        if(s.length() != t.length()){
            return false;
        }

        vector<int> count(26, 0);

        for(int i = 0; i < s.length(); i++){

            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int num : count){

            if(num != 0){
                return false;
            }
        }

        return true;
    }
};

static const auto __accel_stdio = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::unitbuf; // Opzionale, vedi nota sotto
    return 0;
}();