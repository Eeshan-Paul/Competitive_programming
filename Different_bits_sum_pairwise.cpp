int mod(long long a)
{
    int mod=1000000007;
    return ((a % mod) + mod) % mod;
}

int add(long long a,long long b)
{
    int mod=1000000007;
    return ((a % mod) + (b % mod)) % mod;
}


int multiply (long long a , long long b)
{
    int mod=1000000007;
    return ((a % mod) * (b % mod)) % mod;
}

int Solution::cntBits(vector<int> &A) {
    int n=A.size();
    int res=0;
    for (int i=0;i<32;i++)
    {
        int count=0;
        for (int j=0;j<n;j++)
        {
            if (A[j] & (1<<i)) // ((A[j] >>i) & 1) 
                count++;
        }
        res=add(res , multiply(count,n-count));
    }
    return multiply(2,res);
}
