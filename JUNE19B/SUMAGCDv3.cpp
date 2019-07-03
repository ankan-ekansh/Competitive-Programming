/*
    Accepted
 */

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
 
        int s;
        cin>>s;
        vector<int> a;
        for(int i=0;i<s;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        vector<int>::iterator it = unique(a.begin(), a.begin()+s);
        a.resize(distance(a.begin(), it));
        int n = a.size();
        if(n == 1){
            cout<<2*a[0]<<"\n";
            continue;
        }
        int pr[n]={0},po[n]={0};
        pr[0]=a[0];
        po[n-1]=a[n-1];
        //cout<<pr[0]<<" ";
        for(int i=1;i<n;i++){
            pr[i]=__gcd(pr[i-1], a[i]);
            //cout<<pr[i]<<" ";
        }
        //cout<<"\n";
        for(int i=n-2;i>=0;i--){
            po[i]=__gcd(po[i+1], a[i]);
        }
        //for(int i=0;i<n;i++){
            //cout<<po[i]<<" ";
        //}
        //cout<<"\n";
        int m_sum = 0;
        for(int i=0;i<n;i++){
            if(i == 0){
                int s = a[0] + po[1];
                if(s > m_sum){
                    m_sum = s;
                }
            }
            else if(i == n-1){
                int s = a[n-1] + pr[n-2];
                if(s > m_sum){
                    m_sum = s;
                }
            }
            else{
                int s = a[i] + __gcd(pr[i-1], po[i+1]);
                if(s > m_sum){
                    m_sum = s;
                }
            }
        }
        cout<<m_sum<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}