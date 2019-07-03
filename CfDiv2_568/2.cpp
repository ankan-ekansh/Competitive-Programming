#include<bits/stdc++.h>
using namespace std;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        string s1, s2;
        cin>>s1;
        cin>>s2;
        vector<pair<char, int>> v1,v2;
        int l1 = s1.size();
        int l2 = s2.size();
        v1.push_back(make_pair(s1[0], 1));
        int j=1;
        for(int i=1;i<l1;i++){
            if(s1[i] != s1[i-1]){
                v1.push_back(make_pair(s1[i], 1));
                j++;
            }
            else{
                v1[j-1].second++;
            }
        }

        v2.push_back(make_pair(s2[0], 1));
        int k=1;
        for(int i=1;i<l2;i++){
            if(s2[i] != s2[i-1]){
                v2.push_back(make_pair(s2[i], 1));
                k++;
            }
            else{
                v2[k-1].second++;
            }
        }
        
        // for(int i=0;i!=j;i++){
        //     cout<<v1[i].first<<" "<<v1[i].second<<"\n";
        // }
        // cout<<"\n";

        // for(int i=0;i!=k;i++){
        //     cout<<v2[i].first<<" "<<v2[i].second<<"\n";
        // }
        // cout<<"\n";
        bool flag = true;
        if(k != j){
            //cout<<"NO\n";
            //cout<<"1st\n";
            flag = false;
        }
        else if(k == j){
            for(int i=0;i!=k;i++){
                if(v1[i].first != v2[i].first){
                    //cout<<"NO\n";
                    //cout<<"2nd\n";
                    flag = false;
                    break;
                }
                else if(v1[i].second > v2[i].second){
                    //cout<<"NO\n";
                    //cout<<"3rd\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

 
    }
    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}