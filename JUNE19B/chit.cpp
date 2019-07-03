#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long int
const int MAXN = 10005;
ll N,K,A[MAXN],X;
vector<pair<ll,ll> > lesser;
vector<pair<ll,ll> > great;
ll prelesserXor[MAXN], prelesserArray[MAXN], pregreatXor[MAXN], pregreatArray[MAXN];
bool myfun(pair<ll,ll> &a, pair<ll,ll> &b) { 
	if(a.second-a.first<b.second-b.first) return true;
	if(a.second-a.first==b.second-b.first) {
		if(a.second<=b.second) return true;
		return false;
	}
	return false;
}
bool myfun2(pair<ll,ll> &a, pair<ll,ll> &b) { 
	if(a.first-a.second<b.first-b.second) return true;
	if(a.first-a.second==b.first-b.second) {
		if(a.second<=b.second) return true;
		return false;
	} 
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		cin>>N;
		lesser.clear();
		great.clear();
		ll Sum=0;
		for(int i=1;i<=N;i++) {
			cin>>A[i];
			Sum+=A[i];
		}
		cin>>K;
		cin>>X;
		for(int i=1;i<=N;i++) {
			if((A[i]^X)<=A[i]) {
				lesser.pb(mp(A[i]^X,A[i]));
			} else {
				great.pb(mp(A[i]^X,A[i]));
			}
		}
		if(great.size()==0) {
			cout<<Sum<<endl;
			continue;
		}
		sort(lesser.begin(),lesser.end(),myfun);
		sort(great.begin(),great.end(),myfun2);      
        for(int i=0;i<MAXN;i++){
         pregreatXor[i] =0;
         pregreatArray[i]=0;
         prelesserArray[i]=0;
         prelesserXor[i]=0;
         }
		ll n = great.size(); 
		ll m = lesser.size();
		pregreatXor[0]=pregreatArray[0]=prelesserArray[0]=prelesserXor[0]=0;
		for(int i=0;i<n;i++) {
			pregreatXor[i+1] = great[i].first+pregreatXor[i];
			pregreatArray[i+1] = great[i].second+pregreatArray[i];
		}
		for(int i=0;i<m;i++) {
			prelesserArray[i+1] = lesser[i].second + prelesserArray[i];
			prelesserXor[i+1] = lesser[i].first + prelesserXor[i];
		}
		ll a,b,timesa,moda,timesb,modb; 
		ll ans = Sum;
		a = K;
        if(K>n){
         ans = max(ans, pregreatXor[n] +prelesserXor[K-n]+ prelesserArray[m]- prelesserArray[K-n] );
         cout<<ans<<endl;
        continue;
        }
		timesa = n/a;
		moda = n%a;
		if(moda==0) {
			ans = max(ans, pregreatXor[n]+prelesserArray[m]);
		} else {
				ans = max(ans, pregreatXor[n]+prelesserXor[a-moda]+prelesserArray[m]-prelesserArray[a-moda]);
				ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserArray[m]);
				moda = a-moda;
				ans = max(ans, pregreatXor[n]+prelesserXor[a-moda]+prelesserArray[m]-prelesserArray[a-moda]);
				ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserArray[m]);
		}
		for(int i=1;i<=K-1;i++) {
			a = K-i;
			b = i;
			timesa = n/a;
			moda = n%a;
			if(moda==0) {
				if(timesa%2==0) {
					ans = max(ans, pregreatXor[n]+prelesserArray[m]);
				} else {
					ans = max(ans, pregreatArray[n]+prelesserXor[b]+prelesserArray[m]-prelesserArray[b]);
				}
			} else {
				if(timesa%2==0) {
					ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserArray[m]);
					ans = max(ans, pregreatArray[n]+prelesserXor[K-moda]+prelesserArray[m]-prelesserArray[K-moda]);
					moda = a-moda;
					ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserXor[b]+prelesserArray[m]-prelesserArray[b]);
					b = b-(K-moda);
					if(b>0) 
					ans = max(ans, pregreatXor[n]+prelesserXor[b]+prelesserArray[m]-prelesserArray[b]);
				} else {
					ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserArray[m]);
					ans = max(ans, pregreatArray[n]+prelesserXor[K-moda]+prelesserArray[m]-prelesserArray[K-moda]);
					moda = a-moda;
					ans = max(ans, pregreatXor[n]-pregreatXor[moda]+pregreatArray[moda]+prelesserXor[b]+prelesserArray[m]-prelesserArray[b]);
					b = b-(K-moda);
					if(b>0) 
					ans = max(ans, pregreatXor[n]+prelesserXor[b]+prelesserArray[m]-prelesserArray[b]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}