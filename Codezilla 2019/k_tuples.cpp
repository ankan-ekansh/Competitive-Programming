#include <bits/stdc++.h>
using namespace std; 

#define M 1000000007
#define MAXN 1000001 

long fact[1000007];

long power(long m, long n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return m;
    }
    else{
        long x = power(m, n/2);
        if(n % 2 == 0){
            return ((x%M)*(x%M))%M;
        }
        else{
            return ((( (x%M)*(m%M)) % M ) * (x%M) ) % M;
        }
    }
}
long spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (long i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (long i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (long i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (long j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<long> getFactorization(long x) 
{ 
    vector<long> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

// driver program for above function 
int main() 
{ 
	// precalculating Smallest Prime Factor 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(fact, 0, sizeof(fact));
    fact[0] = 1;
    for(long i=1;i<=1000000;i++){
        fact[i]=((fact[i-1]%M)*i)%M;
        // fact[i] = fact[i-1] * i;
    }
    // cout << fact[0] << "\n";
	sieve(); 
    long t;
    cin >> t;
    while(t--){
        long n, k;
        cin >> n >> k;
        long x = fact[n]; 
        cout << "prime factorization for " << x << " : \n"; 

        // calling getFactorization function 
        vector <long> p = getFactorization(x); 
        map<long, long> m;
        for (long i=0; i<p.size(); i++) {
            cout << p[i] << " "; 
            m[p[i]]++;
        }
        cout << "\n";
        long c = 0;
        for(auto i=m.begin();i!=m.end();i++){
            // cout << (*i).second << "\n";
            c+=(*i).second;
        }
        cout << c << "\n";
        m[1] = k - c;
        long ans = fact[k];
        // cout << ans << "\n";
        for(auto i=m.begin();i!=m.end();i++){
            // cout << power((*i).second, M-2) << "\n";
            // ans = (ans * power((*i).second, M-2))%M;
            // cout << ans << "\n";
            // cout << (*i).second << "\n";
        }
        // cout << ans ;
        cout << endl; 
    }
	return 0; 
} 
