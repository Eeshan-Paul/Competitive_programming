#include<bits/stdc++.h>
using namespace std;

int *Z_algo(string s,int n){
    int *z=new int[n];
    z[0]=0;
    int l=0,r=0;
    for (int i=1;i<n;i++){
        //Condition 1
        if (i>r){
            l=i;
            r=i;
            while (r<n && s[r-l]==s[r]){
                r++;
            }
            r--;
            z[i]=r-l+1;
        }
        else{
            int j=i-l;
            if (z[j]<r-i+1){
                z[i]=z[j];
            }
            else{
                l=i;
                while (r<n && s[r-l]==s[r]){
                    r++;
                }
                r--;
                z[i]=r-l+1;
            }
        }
    }
    return z;
}


int main(){
    string s;
    cin>>s;
    int n=s.size();
    int *z=new int[n];
    z=Z_algo(s,n);
    for (int i=0;i<n;i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    return 0;
}