#include<bits/stdc++.h>
using namespace std;
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
        int n,m,k,l;
        cin>>n>>m>>k>>l;
        vector <int> ts;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int t=1, i=0,j=1;t<=k;t++){
            if(m==0 && (t+1)%l==0){
                ts.push_back(1);
                m++;
                break;
            }

            if(t==l*j){
                m--;
                ts.push_back((m+1)*l);
                j++;
            }
            if(t==a[i] && i!=n){
                m++;
                i++;
                ts.push_back((m-1)*l + (l*(j)-t));
            }
            if(t==l*j &&(t==a[i] && i!=n)){
                ts.push_back(m*l);
                j++;
            }
                if(t+1 == k){
                ts.push_back(l*(m) +1 );
                break;

            }


        }
        ts.push_back((m+1)*l);

        sort(ts.begin(),ts.end());
        cout<<*ts.begin()<<"\n";
        ts.clear();
    }


/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
