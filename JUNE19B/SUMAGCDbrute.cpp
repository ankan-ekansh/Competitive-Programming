#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        vector<int>::iterator it = unique(a.begin(), a.begin()+n);
        a.resize(distance(a.begin(), it));
        int s = a.size();
        int g=1,sum_max = 0;
        bool found = false;
        if(s == 1){
            cout<<2*a[0]<<"\n";
            continue;
        }
        else if(s == 2){
            cout<<a[0]+a[1]<<"\n";
            continue;
        }
        for(int i=0;i<s;i++){
            // if(i == 0){
            //     g = a[1];
            // }
            // else{
            //     g = a[0];
            // }
            //cout<<a[i]<<"\n";
            for(int j=0;j<s;j++){
                if(j==i){
                    continue;
                }
                if(!found){
                    g = a[j];
                    found = true;
                    //cout<<a[j]<<" ";
                    continue;
                }
                //cout<<a[j]<<" ";
                g = __gcd(g,a[j]);
            }
            found = false;
            //cout<<"\ng = "<<g<<"\n";
            if(a[i] + g > sum_max){
                sum_max = a[i] + g;
            }
        }
        cout<<sum_max<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}