#include<bits/stdc++.h>
using namespace std;
string conv(int y){
    string s;
    for(int i=0;i<y;i++){
        s.append("0");
    }
    s.insert(0,"1");
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x,y;
    cin>>n>>x>>y;
    string a;
    cin>>a;
    string b = conv(y);
    cout<<a<<"\n";
    cout<<b<<"\n";
    int c = 0;
    int j = y;
    for(int i = n-1;i>x;i--){
        if(j>=0){
            if(a[i] != b[j]){
                c++;
            }
            j--;
        }
        else{
            if(a[i] == '1'){
                a[i] = '0';
                c++;
            }
        }
    }
    cout<<c<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}