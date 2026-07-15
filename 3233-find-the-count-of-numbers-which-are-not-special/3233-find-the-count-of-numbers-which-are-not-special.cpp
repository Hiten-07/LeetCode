class Solution {
public:
    int nonSpecialCount(int l, int r) {
        const int LIMIT = 31623; // ceil(sqrt(1e9))

        // Sieve of Eratosthenes up to LIMIT
        vector<bool> isPrime(LIMIT + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= LIMIT; i++)
            if (isPrime[i])
                for (int j = i * i; j <= LIMIT; j += i)
                    isPrime[j] = false;

        // Count prime squares p² in [l, r]
        // p² in [l,r] <=> p in [ceil(sqrt(l)), floor(sqrt(r))]
        int lo = (int)ceil(sqrt((double)l));
        int hi = (int)floor(sqrt((double)r));

        int specialCount = 0;
        for (int p = lo; p <= hi; p++)
            if (p <= LIMIT && isPrime[p])
                specialCount++;

        return (r - l + 1) - specialCount;
    }
};