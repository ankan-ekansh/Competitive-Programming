#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("inputfancy.txt", "rt", stdin);
        freopen("outputfancy.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    cin.get();
    while(t--){

        string str;
        char s[6];
        getline(cin,str);
        str.push_back(' ');
        str = ' '+str;
        string::iterator it;
        int flag = 1;
        for(it = str.begin();it!=str.end();it++){
//            cout<<*it<<endl;
            if (*it == ' '){
                str.copy(s,5,(it-str.begin()));
//                cout<<s<<endl;
                if((s[0] == ' ') && (s[1]=='n') && (s[2]=='o') && (s[3]=='t') && (s[4]==' ')){
                    flag = 0;
                    break;
                }

            }
        }
        if(flag == 1){
            cout<<"regularly fancy\n";
        }
        else
            cout<<"Real Fancy\n";

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

