#include<bits/stdc++.h>
using namespace std;
int n,m;
int i,j;
int a[350][350];
vector <int> r;
vector <int> c;
vector <int> mandist;
int dist(int r1, int r2, int c1, int c2){
    int d=0;
    if(r2>r1)
        d=r2-r1;
    else
        d=r1-r2;
    if(c2>c1)
        d+=c2-c1;
    else
        d+=c1-c2;
    return d;
}
int asgn(char s[]){
    for(j=0;j<m;j++){
        if(s[j]=='0')
            a[i][j]=0;
        if(s[j]=='1'){
            a[i][j]=1;
            r.push_back(i);
            c.push_back(j);
        }
    }
}
int main(){
  #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=0;i<n;i++){
            char s[m];
            cin>>s;
            asgn(s);
        }
     for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }

        for(i=0;i<r.size();i++){
            for(j=i+1;j<r.size();j++){
                int tempdist = dist(r[i],r[j],c[i],c[j]);
                mandist.push_back(tempdist);
            }
        }
        sort(mandist.begin(),mandist.end());
      for(i=0;i<r.size();i++){
            cout<<"["<<r[i]<<"]"<<"["<<c[i]<<"]"<<"\n";
        }

        for(i=0;i<mandist.size();i++){
            cout<<mandist[i]<<"\n";
        }
        for(int d=1,i=0;d<=(n+m-2);d++){
            if(mandist[i]==d){
                cout<<"1 ";
                i++;
            }
            else{
                cout<<"0 ";
            }
        }

        cout<<endl;



    }


   #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif

    return 0;
}
