class Solution {
public:
    int minSteps(string s, string t) {
        int count1[256]={0};
        int count2[256]={0};
        int sum=0;
        int n=s.length();
        for (int i=0;i<n;i++){
            count1[s[i]]++;
            count2[t[i]]++;
        }
        int sum1=0,sum2=0;
        for (int i=0;i<256;i++){
            if (count1[i]>0 && count2[i]>0 && count1[i]>count2[i]){
                sum1+=(count1[i]-count2[i]);
            }
            else if (count1[i]>count2[i])
                sum1+=count1[i];
            if (count2[i]>0 && count1[i]>0 && count2[i]>count1[i]){
                sum2+=(count2[i]-count1[i]);
            }
            else if (count2[i]>count1[i])
                sum2+=count2[i];
        }
        return min(sum1,sum2);
    }
};