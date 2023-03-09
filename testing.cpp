#include<bits/stdc++.h>
    using namespace std;
 
    #define ff              first
    #define ss              second
    #define int             long long
    #define pb              push_back
    #define pii             pair<int,int>
    #define vi              vector<int>
    #define mii             map<int,int>
    #define pqb             priority_queue<int>
    #define pqs             priority_queue<int,vi,greater<int> >
    #define setbits(x)      __builtin_popcountll(x)
    #define zrobits(x)      __builtin_ctzll(x)
    #define inf             1e18
    #define ps(x,y)         fixed<<setprecision(y)<<x
    #define mk(arr,n,type)  type *arr=new type[n];
    #define f(x)            int x; cin>>x; while(x--)
    #define rep(i,a,b)      for (long long i=a;i<b;i++)
    #define rof(i,a,b)		for (int i=a;i>=b;i--)
    #define multiply(n)     ((n*(n+1))/2)
    #define BLOCK           555
    #define mod             1000000007
    #define sz(x) (int)(x).size()
    mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
    void setIO(string name = "") {
        if(sz(name)){
            freopen((name+".in").c_str(), "r", stdin);
            freopen((name+".out").c_str(), "w", stdout);
        }
    }
 
    
    void solve()
    {   
            int n,c;cin>>n>>c;
            int num[n];
            for(int i=0;i<n;i++){
               cin>>num[i];
               num[i]+=i+1;
            }
            sort(num,num+n);
            int i=0;
            int count=0;
            while(i<n &&c>=num[i] ){
                c=c-num[i];
                count++;
                i++;
            }
            cout<<(count)<<endl;
    }
 
    int32_t main()
    {
        ios_base::sync_with_stdio(0); cin.tie(0);
        f(t) 
        solve();
        return 0;
    }