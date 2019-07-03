#include<bits/stdc++.h>
//#include<boost/math/common_factor.hpp>
#define ll long long int
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){

        ll n,a,b;
        cin>>n>>a>>b;
//        ll c = boost::math::lcm(a,b);
        ll c = (a*b)/(__gcd(a,b));
        ll arr[n];
        ll l=0;
        ll i,j;
        for(i=0;i<n;i++){
            cin>>arr[i];
            if(l>arr[i]){
                l=arr[i];
            }
        }
        sort(arr,arr+n);
        ll d = (l/c)*c;
        ll pos = binary_search(arr,arr+n,c);
        ll pa=0,pb=0;
        for(i=pos,j=1;i<n;i++){
            if(arr[i]>d){
                break;
            }
            if(arr[i]%c == 0){
                if(j%2!=0){
                    pa++;
                    j++;
                }
                else{
                    pb++;
                    j++;
                }
            }
        }
        for(i=0,j=1;i<n;i++){
                if(arr[i]%a == 0 && arr[i]%c != 0 && j%2 != 0){
                    pa++;
                    j++;
                }
                if(arr[i]%b == 0 && arr[i]%c != 0 && j%2 == 0){
                    pb++;
                    j++;
                }
        }

        if(pa>pb){
            cout<<"BOB\n";
        }
        else if(pa<pb){
            cout<<"ALICE\n";
        }
        else if(pa==pb){
            if(j%2!=0){
                cout<<"ALICE\n";
            }
            else
                cout<<"BOB\n";
        }

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

