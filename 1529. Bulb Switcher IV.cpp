class Solution {
public:
    int minFlips(string target) {
        int count=0;
        char check='0';
        for (int i=0;i<target.length();i++){
            if (check!=target[i]){
                check=target[i];
                count++;
            }
        }
        return count;
    }
};