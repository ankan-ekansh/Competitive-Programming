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
        a1=(v[i].find_first_of(" "))+1;
        a2=(v[i].find_last_of("="))-1;
        v1=(v[i].find_first_of("\""))+1;
        v2=(v[i].find_last_of("\""))-1;
        t1=(v[i].find_first_of("<"))+1;
        t2=(v[i].find_first_of(" ")-1);
        if(a1<len && a2<len && v1<len && v2<len && t1<len && t2<len && v[i].find_first_of("/")!=t1){
            at.push_back(v[i].substr(a1,a2));
            val.push_back(v[i].substr(v1,v2));
            t.push_back(v[i].substr(t1,t2));
        }    
    }
    for(int i=0;i<q;i++){
        string s;
        getline(cin,s);
        qry.push_back(s);
        if(qry[i].find_first_of(".")>qry[i].length())
            tt.push_back(qry[i].substr(0,qry[i].find_first_of("~")-1));
        else
            tt.push_back(qry[i].substr(qry[i].find_first_of(".")+1,qry[i].find_first_of("~")-1));
        att.push_back(qry[i].substr(qry[i].find_first_of("~")+1,qry[i].length()-1));
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
