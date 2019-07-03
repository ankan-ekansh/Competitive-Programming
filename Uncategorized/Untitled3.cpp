#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    int a1,a2,v1,v2,t1,t2;
    cin>>n>>q;
    vector<string> v;
    vector<string> at;
    vector<string> val;
    vector<string> qry;
    vector<string> t;
    vector<string> tt;
    vector<string> att;
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        v.push_back(s);

    }
    for(int i=0;i<n;i++){
        int len=v[i].length();
        a1=(v[i].find_first_of(" "));
        a2=(v[i].find_first_of("="));
        v1=(v[i].find_first_of("\""));
        v2=(v[i].find_last_of(">"));
        t1=(v[i].find_first_of("<"));
        t2=(v[i].find_first_of(" "));
        if(a1<len && a2<len && v1<len && v2<len && t1<len && t2<len && v[i].find_first_of("/")!=(t1+1)){
            at.push_back(v[i].substr(a1+1,a2-1));
            val.push_back(v[i].substr(v1+1,v2-2));
            t.push_back(v[i].substr(t1+1,t2-1));
        }
    }
    for(int i=0;i<n;i++){
        cout<<val[i]<<endl;
    }
    for(int i=0;i<q;i++){
        string s;
        getline(cin,s);
        qry.push_back(s);
        int r1,r2,s1,s2;
        r1=(qry[i].find_first_of("."));
        r2=(qry[i].find_first_of("~"));
        s1=(qry[i].find_first_of("~"));
        s2=(qry[i].length());
        if(r1>s2 && r2<s2 && s1<s2 )
            tt.push_back(qry[i].substr(0,r2-1));
        else if(r1<s2 && r2<s2 && s1<s2)
            tt.push_back(qry[i].substr(r1+1,r2-1));
        if(r1<s2 && r2<s2 && s1<s2 )
        att.push_back(qry[i].substr(s1+1,s2-1));
    }

    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(tt[i].compare(t[j])==0){
                if(att[i].compare(at[j])==0){
                    cout<<val[j]<<endl;
                }
                else
                    cout<<"Not Found!"<<endl;
            }
        }
    }
    return 0;
}
