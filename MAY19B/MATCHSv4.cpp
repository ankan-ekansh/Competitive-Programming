#include<bits/stdc++.h>
using namespace std;
int64_t c;
void next_turn(){
    c=1-c;
}
int64_t possible(int64_t n,int64_t m){
    long double r = (double)n/(double)m;
    if(r-3 >= 0){
        cout<<"First r\n";
        return (int64_t)r;
    }
    else{
        cout<<"Second r\n";
        return (int64_t)r+1;
    }
    // if((int64_t)r >=2 && m%(n%m)!=0){
    //     return (int64_t)r;
    // }
    // else{
    //     bool flag = false;
    //     while((int64_t)r > 0){
    //         n = n -r*m;
    //         if(n<m){
    //             swap(n,m);
    //         }
    //         if(n%m==0){
    //             r--;
    //             continue;
    //         }
    //         else{
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         return r;
    //     }
    //     else{
    //         return 2;
    //     }
    // }
}
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
 
        int64_t n,m;
        cin>>n>>m;
        if(n<m){
            swap(n,m);
        }
        if(n%m == 0){
            cout<<"Ari\n";
            continue;
        }
        else{
            c=0;
            while(n>0 && m>0){
                cout<<"\nCurrent turn: "<<c<<"\n";
                if(n<m){
                    swap(n,m);
                }
                int64_t r = possible(n,m);
                if(r>1 && n%m!=0){
                    cout<<"First if\n";
                    cout<<"Before logic ratio: "<<n<<" "<<m<<"\n";
                    cout<<"Ratio: "<<r<<"\n";
                    n = n - (r-1)*m;
                    cout<<"Ratio after logic:\n";
                    cout<<n<<" "<<m<<"\n";
                    next_turn();
                }
                else{
                    cout<<"Else part\n";
                    cout<<"Before removing\n";
                    cout<<n<<" "<<m<<"\n";
                    if(n%m==0){
                        cout<<"After removing\n";
                        cout<<n%m<<" "<<m<<"\n";
                        break;
                    }
                    else{
                        n=n%m;
                    }
                    cout<<"After removing\n";
                    cout<<n<<" "<<m<<"\n";
                    next_turn();
                }
                if(n==0 || m==0){
                    break;
                }
                // if(n%m==0){
                //     next_turn();
                //     break;
                // }
                // long double r = (long double)n/(long double)m;
                // if(r-2>=0 && n%m!=0){
                //     cout<<"First if\n";
                //     cout<<"Before ratio logic: "<<n<<" "<<m<<"\n";
                //     next_turn();
                //     cout<<r<<"\n";
                //     //n = n - ((int64_t)r-1)*m;
                //     n = n - (floor(r)-1)*m;
                //     cout<<"After ratio logic:\n";
                //     cout<<n<<" "<<m<<"\n";
                // }
                // else{
                //     //cout<<n<<"\n";
                //     cout<<"Else part\n";
                //     cout<<"Before removing\n";
                //     cout<<n<<" "<<m<<"\n";
                //     n=n%m;
                //     cout<<"After removing\n";
                //     cout<<n<<" "<<m<<"\n";
                //     if(n<m){
                //         swap(n,m);
                //     }
                //     if(n==0 || m==0){
                //         break;
                //     }
                //     next_turn();
                //     // if(n%m!=0)
                //     //     next_turn();
                //     // else{
                //     //     //next_turn();
                //     //     break;
                //     // }
                    
                //}
            }
        }
        //next_turn();
        if(c==0){
            cout<<"Ari\n";
        }
        else{
            cout<<"Rich\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}