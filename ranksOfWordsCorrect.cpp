#define MOD 1000003

void initializeFactorials(int totalLen, vector<int> &fact) {
    long long int factorial = 1;
    fact.push_back(1); // 0!= 1
    for (int curIndex = 1; curIndex < totalLen; curIndex++) {
        factorial = (factorial * curIndex) % MOD;
        fact.push_back(factorial);
    }
    return;
}

long long int inverseNumber(int num) {
    long long int ans = 1, base = (long long) num;
    int power = MOD - 2;
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % MOD;
        }
        if (power % 2 == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            ans = (ans * base) % MOD;
            power--;
        }
    }
    return ans;
}

int Solution::findRank(string S) {
    
    int charCount[256]; 
    memset(charCount, 0, sizeof(charCount));
    for (int i = 0; i < S.length(); i++) 
        charCount[S[i]]++;

    vector<int> fact;
    initializeFactorials(S.length() + 1, fact);

    long long int rank =  1;
    for (int i = 0; i < S.length(); i++) 
    {
        long long int less = 0;
        int remaining = S.length() - i - 1;
        for (int ch = 0; ch < S[i]; ch++) 
        {
            if (charCount[ch] == 0) 
            continue;
            charCount[ch]--;
            long long int numPermutation = fact[remaining];
            
            for (int c = 0; c < 128; c++) 
            {
                if (charCount[c] <= 1) 
                    continue; 
                numPermutation = (numPermutation * inverseNumber(fact[charCount[c]])) % MOD;
            }

            charCount[ch]++;
            less = (less + numPermutation) % MOD;
        }
        
        rank = (rank + less) % MOD;
        charCount[S[i]]--;
    }
    return rank;
}