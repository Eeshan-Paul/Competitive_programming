class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for (int i=0;i<words.size();i++){
            if (words[i].length()!=pattern.length())
                continue;
            int count[256];
            int count1[256];
            for (int j=0;j<256;j++){
                count[j]=-1;
                count1[j]=-1;
            }
            int j=0;
            for (j;j<words[i].length();j++){
                if (count[words[i][j]]!=count1[pattern[j]])
                    break;
                count[words[i][j]]=j;
                count1[pattern[j]]=j;
            }
            if (j==words[i].length())
            v.push_back(words[i]);
        }
        return v;
    }
};