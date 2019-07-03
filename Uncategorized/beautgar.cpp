#include<bits/stdc++.h>
using namespace std;
int check(string str2){
    string::iterator i,j;
    int flag = 0;
    for(i=str2.begin(),j=str2.begin()+1;i!=str2.end(),j!=str2.end();i++,j++){
        if(*i == *j){
            flag=1;
            break;
        }
    }

    return flag;
}
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
        string str;
        string str2;
        string strp;
        getline(cin,str);
        string::iterator it;
        string::iterator il;
        int flag = 0;
        int l=sizeof(str)/sizeof(str[0]);
        for(it=str.begin();it!=str.end();it++){
            cout<<*it;
        }
        cout<<"\n";
        for(int i=0;i<l;i++){
            if(str[i-1]==str[i]){
                size_t found;
                if(str[i]=='R'){
                    string gp = {"G"};
//                    il = search(str.begin()+i,str.end(),gp.begin(),gp.end());
  //                  cout<<il<<"\n";

                    found = str.find(gp);
                    if (found != string::npos)
                        cout<<gp<<"found at:"<<found<<"\n";

                    }
                    else{
                    string gp = {"R"};
  //                  il = search(str.begin()+i,str.end(),gp.begin(),gp.end());
  //                  cout<<il<<"\n";

                    found = str.find(gp);
                       if (found != string::npos)
                        cout<<gp<<"found at:"<<found<<"\n";

                }
                if (found != string::npos){
                    int lp = found+1;
                    cout<<"length of part "<<lp<<"\n";
                    str2 = str.substr(0,i);
                                        cout<<"str2 :"<<str2<<"\n";
                    strp = str.substr(i,lp+1);

                    reverse(strp.begin(),strp.end());
                    str2.append(strp);
                    string strrem = str.substr(i+lp,l-(sizeof(str2))/(sizeof(str2[0]))+1);
                    str2.append(strrem);
                    flag = check(str2);

                }
            }
        }
        if(flag == 0 && str2[0]!=str2[l-1]){
            cout<<"yes\n";
        }
        else
            cout<<"no\n";

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

