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
    for(int i=0;i<n;i++){
        int a1,a2,v1,v2,t1,t2;
        cout<<v[i]<<endl;
        a1=(v[i].find_first_of(" "));
        a2=(v[i].find_first_of("="));
        v1=(v[i].find_first_of("\""));
        v2=(v[i].find_last_of("\""));
        t1=(v[i].find_first_of("<"));
        t2=(v[i].find_first_of(" "));
        cout<<t1<<" "<<t2<<" "<<a1<<" "<<a2<<" "<<v1<<" "<<v2<<endl;
        if(a1>=0 && a2>=0)
            at.push_back(v[i].substr(a1+1,a2));
        if(v1>=0 && v2>=0)
            val.push_back(v[i].substr(v1+1,v2));
        if(t1>=0 && t2>=0)
            t.push_back(v[i].substr(t1+1,t2));
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
        if(r1<0 && r2>=0)
            tt.push_back(qry[i].substr(0,r2));
        else if(r1>=0 && r2>=0)
            tt.push_back(qry[i].substr(r1+1,r2));
        if(s1>=0 && s2>=0)
        att.push_back(qry[i].substr(s1+1,s2));
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
