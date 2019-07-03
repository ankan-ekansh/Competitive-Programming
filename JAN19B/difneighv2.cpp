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

        int n,m;
        cin>>n>>m;
        if(n==1 && m==1){
            cout<<"1\n";
            cout<<"1\n";
            continue;
        }
        if(n==1 && m>2){
            cout<<"2\n";
            int c = 1;
            for(int i=0;i<m;i++){
                cout<<c<<" ";
                i++;
                if(i>=m){
                    cout<<endl;
                    break;
                }
                cout<<c++<<" ";
                if(i+1>=m){
                    cout<<endl;
                    break;
                }
                if(c==3){
                    c=1;
                }
            }
            continue;
        }
        if(n==1 && m==2){
            cout<<"1\n";
            cout<<"1 1\n";
            continue;
        }
        if(n==2 && m==1){
            cout<<"1\n";
            cout<<"1\n";
            cout<<"1\n";
        }
        if(m==1 && n>2){
            int a[n];
            cout<<"2\n";
            int c = 1;
            for(int i=0;i<n;i++){
                a[i] = c;
                i++;
                if(i>=n){
                    break;
                }
                a[i] = c++;
                if(c==3){
                    c=1;
                }

            }
            for(int i = 0;i<n;i++){
                cout<<a[i]<<endl;
            }
            continue;
        }
        if(n==2 && m==2){
            cout<<"2\n";
            cout<<"1 2\n";
            cout<<"1 2\n";
            continue;
        }
        if(n==2 && m>2){
            int a[n][m];
            cout<<"3\n";
            int c=0;
            for(int i=0;i<m;i++){
                a[0][i] = ++c;
                a[1][i] = c;
                i++;
                if(i>=m){
                    break;
                }
                if(c==3){
                    c=0;
                }
                a[0][i] = ++c;
                a[1][i] = c;
                if(c==3){
                    c=0;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            continue;
        }
        if(m==2 && n>2){
            int a[n][m];
            cout<<"3\n";
            int c=0;
            for(int i=0;i<n;i++){
                a[i][0]=++c;
                a[i][1]=c;
                i++;
                if(i>=n){
                    break;
                }
                if(c==3){
                    c=0;
                }
                a[i][0]=++c;
                a[i][1]=c;
                if(c==3){
                    c=0;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            continue;
        }
        else{
            int a[n][m]={0};
            cout<<"4\n";
            int c=0;
            int pos = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    a[i][j]=++c;
                    if(c==4){
                        c=0;
                    }
                }
                i++;
                if(i>=n){
                    break;
                }
//                c=0;
                for(int j=0;j<m;j++){
                    a[i][j]=a[i-1][j];
//                    a[i][j]=++c;
//                    if(c==4){
//                        c=0;
//                    }
                }
                i++;
                if(i>=n){
                    break;
                }
                pos=2;
                c = 4;
                for(int j=pos-1;j>=0;j--){
                    a[i][j]=c--;
                }
                c = 0;
                for(int j=pos;j<m;j++){
                    a[i][j]=++c;
                    if(c==4){
                        c=0;
                    }
                }
                i++;
                if(i>=n){
                    break;
                }
//                c=0;
                for(int j=0;j<m;j++){
                    a[i][j]=a[i-1][j];
//                    a[i][j]=++c;
//                    if(c==4){
//                        c=0;
//                    }
                }

            }


            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            continue;
        }

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

