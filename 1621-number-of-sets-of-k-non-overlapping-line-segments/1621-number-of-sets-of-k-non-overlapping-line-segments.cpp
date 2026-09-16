class Solution {
    const long long MOD = 1000000007;
    const int L = 1000;
public:
    int numberOfSets(int n, int k) {

        --n;

        vector<long long> fact(L+1, 1);
        for(int i=2; i<=L; ++i) fact[i]=fact[i-1]*i%MOD;

        auto pow =[&](long long a, long long p) {
            long long res=1;
            while(p>0) {
                if(p&1) res=res*a%MOD;
                a=a*a%MOD;
                p>>=1;
            }
            return res;
        };

        vector<long long> inv(L+1, pow(fact[L], MOD-2));
        for(int i=L-1; i>=0; --i) inv[i]=inv[i+1]*(i+1)%MOD;

        auto C = [&](int a, int b) {
            return (fact[a] * inv[b] % MOD) * inv[a-b] % MOD;
        };

        auto AtleastOne = [&](int a, int b) {
            return C(a-1, b-1);
        };

        auto IncludingZero = [&](int a, int b) {
            return AtleastOne(a+b, b);
        };


        long long sum=0;

        for(int u=k; u<=n; ++u) {
            //how to distribute whitespace * how to separate the available chunk
            sum += IncludingZero(n-u, k+1) * AtleastOne(u, k) % MOD;
            sum %= MOD;
        }

        return (int)sum;
    }
};