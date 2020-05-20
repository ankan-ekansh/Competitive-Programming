#include<bits/stdc++.h>
using namespace std;
bool fun(int m, int s){
    if(s >= 0 && s <= 9*m){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, s;
    cin >> m >> s;
    string a, b;
    int sum = s;
    
    bool flag = false;
    if(s < 1 && m > 1 || s > 9 * m){
        flag = true;
        cout << "-1 -1\n";
    }
    else{
        for(int i=1;i<=m;i++){
            for(int d=0;d<=9;d++){
                if(fun(m-i, s-d)){
                    if(i == 1){
                        if(d == 0){
                            continue;
                        }
                        else{
                            a+=char('0' + d);
                            s-=d;
                            break;
                        }
                    }
                    else{
                        a+=char('0' + d);
                        s-=d;
                        break;
                    }
                }
            }
        }
        s = sum;
        for(int i=m;i>=1;i--){
            for(int d=9;d>=0;d--){
                if(fun(i-1, s-d)){
                    b+=char('0' + d);
                    s-=d;
                    break;
                    // if(i == 1){
                    //     if(d == 0){
                    //         continue;
                    //     }
                    //     else{
                    //         b+=char('0' + d);
                    //         s-=d;
                    //         break;
                    //     }
                    // }
                    // else{
                    //     b+=char('0' + d);
                    //     s-=d;
                    //     break;
                    // }
                }
            }
        }
    }

    if(!flag){
        if(a.size() == 0){
            a+='0';
        }

        cout << a << " " << b << "\n";
    }




    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}