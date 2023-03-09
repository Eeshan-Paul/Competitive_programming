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
    // void print(int index,int k)
    // {
    //     cout<<"Case #"<<index+1<<": "<<k<<endl;
    // }

    bool check(int ham,int b ,int s,int c,int cb,int cs,int cc,int money,string &str)
    {
        int bur=0,sau=0,che=0;
        rep(i,0,str.length()){if (str[i]=='b') bur++;else if (str[i]=='c') sau++;else che++;}
        int tbur=(ham * bur) - b;int tsau=(ham * sau) -s;int tche=(ham * che) -c;
        int total_money=tbur * cb+tsau * cs +tche * cc;
        return total_money<=money;
    }
    
    
    void solve()
    {   
        string str;cin>>str;int b,s,c;cin>>b>>s>>c;int cb,cs,cc;cin>>cb>>cs>>cc;int money;cin>>money;
        int low=1;
        int high=1e16;
        int res=0;
        while (low<=high)
        {
            int mid=(low+high);
            if (check(mid,b,s,c,cb,cs,cc,money,str))
            {
                res=mid;
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        cout<<res<<endl;
    }
 
    int32_t main()
    {
        ios_base::sync_with_stdio(0); cin.tie(0);
        f(t)
        solve();
        return 0;
    }
