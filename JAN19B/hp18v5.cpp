#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){

        int n,a,b;
        cin>>n>>a>>b;
        long long int x;
        int pa=0,pb=0,pc=0;
        if(a==b){
            for(int i=0;i<n;i++){
                cin>>x;
                if(x%a==0){
                    pa++;
                }
            }
            if(pa%2==0){
                cout<<"ALICE\n";
            }
            else{
                cout<<"BOB\n";
            }
        }
        if(a!=b){
//            int c = (a*b)/(__gcd(a,b));
//           cout<<c<<endl;
            for(int i=0;i<n;i++){
                cin>>x;
                if(x%a==0 && x%b==0){
                    pc++;
                }
                if(x%a==0 && x%b!=0){
                    pa++;
                }
                if(x%a!=0 && x%b==0){
                    pb++;
                }
            }
            if(pc%2!=0){
                pa++;
            }
            if(pa>=pb){
                cout<<"BOB\n";
            }
            else if(pa<pb){
                cout<<"ALICE\n";
            }
        }

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

