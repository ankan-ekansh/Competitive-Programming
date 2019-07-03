#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int t;
    cin>>t;
    while(t--){
        long int m,n;
        cin>>n>>m;
        long int h[n];
        long int c[n];
        for(long int i=0;i<n;i++){
            cin>>h[i];
        }
        for(long int i=0;i<n;i++){
            cin>>c[i];
        }
        long int* phmax=max_element(h,h+n);
        long int hmax=*phmax;
        long int w[hmax+1];
        /*
        cout<<hmax<<"\n";
        */
        memset(w,0,sizeof(long int)*(hmax+1));
        for(long int i=0;i<n;i++){
            fill(w+1,w+h[i]+1,c[i]);
/*            memset(w+1,c[i],sizeof(long int)*(h[i]));
*/
  /*         for(int j=1;j<=hmax;j++){
                cout<<w[j]<<" ";
            }
            cout<<"\n";
            */
        }
/*        for(long int i=1;i<=hmax;i++){
            cout<<w[i]<<" ";
        }
        */
        vector <long int> uw;
        for(long int i=1;i<=hmax;i++){
            uw.push_back(w[i]);
        }
    vector<long int>::iterator ip;
    sort(uw.begin(), uw.end());
    ip = unique(uw.begin(), uw.end());
    uw.resize(distance(uw.begin(), ip));
    long int distinct = uw.size();
    cout<<distinct<<"\n";


    }


/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
