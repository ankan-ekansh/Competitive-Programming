#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    cin>>n>>q;
    string s;
    getline(cin,s);
    vector<string> v;
    vector<string> at;
    vector<string> val;
    vector<string> qry;
    vector<string> t;
    vector<string> tt;
    vector<string> att;
    for(int i=0;i<n;i++){
        getline(cin,s);
        v.push_back(s);

    }
    for(int i=0;i<(n/2);i++){
        int a1,a2,v1,v2,t1,t2;
        string ss;
        a1=(v[i].find_first_of(" "));
        a2=(v[i].find_first_of("="));
        v1=(v[i].find_first_of("\""));
        v2=(v[i].find_last_of("\""));
        t1=(v[i].find_first_of("<"));
        t2=(v[i].find_first_of(" "));
        if(a1>=0 && a2>=0){
            ss=v[i].substr(a1+1,a2-a1-2);
            at.push_back(ss);
        }
        if(v1>=0 && v2>=0){
            ss=v[i].substr(v1+1,v2-v1-1);
            val.push_back(ss);
        }
        if(t1>=0 && t2>=0){
            ss=v[i].substr(t1+1,t2-t1-1);
            t.push_back(ss);
        }

    }
    for(int i=0;i<q;i++){
        getline(cin,s);
        qry.push_back(s);
        int r1,r2,s1,s2;
        string ss;
        r1=(qry[i].find_first_of("."));
        r2=(qry[i].find_first_of("~"));
        s1=(qry[i].find_first_of("~"));
        s2=(qry[i].length());
        if(r1<0 && r2>=0){
            ss=qry[i].substr(0,r2);
            tt.push_back(ss);
        }
        if(r1>=0 && r2>=0){
            ss=qry[i].substr(r1+1,r2-r1-1);
            tt.push_back(ss);
        }
        if(s1>=0 && s2>=0){
            ss=qry[i].substr(s1+1,s2-s1-1);
            att.push_back(ss);
        }

    }

    for(int i=0;i<q;i++){
        string qtag = tt[i];
        bool flag = false;
        int pos;
        for(int j=0;j<(n/2);j++){
            string tag = t[j];
            if((qtag.compare(tag)==0)){
                if((att[i].compare(at[j]))==0){
                    flag=true;
                    cout<<val[j]<<endl;
                }
            }
        }
        if(flag==false)  
                cout<<"Not Found!"<<endl;
        }
    return 0;
}
