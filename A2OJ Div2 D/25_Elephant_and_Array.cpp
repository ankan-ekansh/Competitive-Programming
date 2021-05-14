/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
int len, n, m;
vector<pair<pair<int, int>, int>> v;
vector<int> a;
int cnt, cl, cr;
// unordered_map<int, int> freq;
int freq[100007];
int flag;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.ff.ff / len != b.ff.ff / len){
        return a.ff.ff / len < b.ff.ff / len;
    }
    // else{
    //     return a.ff.ss < a.ff.ss;
    // }
    return (a.ff.ff / len & 1) ? (a.ff.ss < b.ff.ss) : (a.ff.ss > b.ff.ss);
}
void add(int pos){
    if(a[pos] > n){
        flag = 0;
        return;
    }
    if(freq[a[pos]] + 1 == a[pos]){
        freq[a[pos]]++;
        cnt++;
    }
    else{
        if(freq[a[pos]] == a[pos]){
            freq[a[pos]]++;
            cnt--;
        }
        else{
            freq[a[pos]]++;
        }
    }
}
void remove(int pos){
    if(a[pos] > n){
        return;
    }
    if(freq[a[pos]] - 1 == a[pos]){
        freq[a[pos]]--;
        cnt++;
    }
    else{
        if(freq[a[pos]] == a[pos]){
            freq[a[pos]]--;
            cnt--;
        }
        else{
            freq[a[pos]]--;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    len = sqrt(n);
    // len = 323;
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        v.push_back({{l, r}, i});
    }
    sort(v.begin(), v.end(), comp);
    cl = 0, cr = -1;
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int l = v[i].ff.ff;
        int r = v[i].ff.ss;
        flag = 1;
        while(cl > l){
            cl--;
            add(cl);
        }
        while(cr < r){
            cr++;
            add(cr);
        }
        while(cl < l){
            remove(cl);
            cl++;
        }
        while(cr > r){
            remove(cr);
            cr--;
        }
        if(flag){
            ans[v[i].ss] = cnt;
        }
        else{
            ans[v[i].ss] = 0;
        }
        
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << "\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}