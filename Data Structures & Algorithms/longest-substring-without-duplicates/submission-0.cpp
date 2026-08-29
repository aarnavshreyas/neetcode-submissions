class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int count=0;
        int left = 0;

        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) != m.end() && m[s[i]] >= left){
                left = m[s[i]] + 1;
            }
            m[s[i]] = i;
            count = max(count, i - left + 1);
        }

        return count;

    }

};

