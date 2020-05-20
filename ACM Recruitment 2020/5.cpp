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

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    stack<int> s;
    stack<int> x;
    int b[n];
    memset(b, 0, sizeof(b));
    s.push(a[0]);
    b[a[0]] = s.size();
    for(int i=1;i<n;i++){
        while(!s.empty() && a[i] > s.top()){
            // if(a[i] < s.top() && a[i] ){
            //     s.push(a[i]);
            //     b[a[i]] = s.size();
            // }
            // else{
            //     s.pop();
            // }
            int t = s.top();
            s.pop();
            x.push(t);
        }
        if(!x.size()){
            s.push(x.top());
            b[s.top()] = s.size();
        }
        else{
            s.push(a[i]);
            b[a[i]] = s.size();
        }
    }
    for(int i=0;i<n;i++){
        cout << b[a[i]] << "\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}