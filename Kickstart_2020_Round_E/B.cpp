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
    int t;
    cin>>t;
    int tc = 1;
    while(t--){
        
        cout << "Case #" << tc++ << ": ";
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        if(n == 1){
            if(a == b && a == c){
                cout << n << "\n";
                continue;
            }
            else{
                cout << "IMPOSSIBLE\n";
                continue;
            }
        }
        if(n == 2){
            if(a == 1 && b == 2 && c == 1){
                cout << 2 << " " << 1 << "\n";
                continue;
            }
            else if(a == 2 && b == 1 && c == 1){
                cout << 1 << " " << 2 << "\n";
                continue;
            }
            else if(a == 2 && b == 2 && c == 2){
                cout << 1 << " " << 1 << "\n";
                continue;
            }
            else{
                cout << "IMPOSSIBLE\n";
                continue;
            }
        }
        // vector<int> left, center, right;
        deque<int> left, center, right;
        for(int i=0;i<c;i++){
            center.push_back(n);
        }
        a = a - c;
        b = b - c;
        int m = n;
        for(int i=0;i<a;i++){
            left.push_back(n-1);
        }
        for(int i=0;i<b;i++){
            right.push_back(n-1);
        }
        if(left.size() + center.size() + right.size() > n){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        bool flag = false;
        while(left.size() + center.size() + right.size() < n){
            if(left.size()){
                left.push_back(n-2);
            }
            else if(right.size()){
                // center.push_back(n-2);
                right.push_front(n-2);
            }
            else{
                cout << "IMPOSSIBLE\n";
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        for(int i : left){
            cout << i << " ";
        }
        for(int i : center){
            cout << i << " ";
        }
        for(int i : right){
            cout << i << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}