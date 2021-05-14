/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int x = 0, y = 0;
    vector<int> xx, yy;
    for(int i=0;i<n;i++){
        if(s[i] == 'a' && t[i] == 'b'){
            x++;
            xx.push_back(i+1);
        }
        else if(s[i] == 'b' && t[i] == 'a'){
            y++;
            yy.push_back(i+1);
        }
    }
    int ans = 0;
    vector<pair<int, int>> v;
    if(x % 2 == 0 && y % 2 == 0){
        ans = (x/2) + (y/2);
    }
    else if(x % 2 != 0 && y % 2 != 0){
        ans = (x/2) + (y/2) + 2;
    }
    else{
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
    for(int i=0;i+1<xx.size();i+=2){
        v.push_back({xx[i], xx[i+1]});
    }
    for(int i=0;i+1<yy.size();i+=2){
        v.push_back({yy[i], yy[i+1]});
    }
    if(x % 2 != 0 && y % 2 != 0){
        v.push_back({xx[x-1], xx[x-1]});
        v.push_back({xx[x-1], yy[y-1]});
    }
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}