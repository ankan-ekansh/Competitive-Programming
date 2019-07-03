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

        string st;
        cin>>st;
        //for(auto i=0;i<st.size();i++){
        //    cout<<st[i];
        //}
        //cout<<endl;
        long long int l = st.size();
        vector<long long int> v;
        string s = st;
        int flag = 0;
        for(auto i=1;i<l;i++){
            string temp1 = s.substr(0,i);
            string temp2 = s.substr(i,l-1);
            long long int x=0;
            long long int y=0;
            //cout<<"temp1:"<<temp1<<" temp2:"<<temp2<<endl;
            if(temp1.size()!=0){
                stringstream z(temp1);
                z>>x;
                //cout<<"x:"<<x<<endl;
            }
            if(temp2.size()!=0){
                stringstream zz(temp2);
                zz>>y;
                //cout<<"y:"<<y<<endl;
            }
            if(temp1.size()==temp2.size()){
                if(x>=y){
                    v.push_back(x);
                    v.push_back(y);
                    flag = 1;
                    break;
                }
            }
            /*if(temp1.size()<temp2.size()){
                if(y==0){
                    v.push_back(x);
                    v.push_back(y);
                    flag = 1;
                    break;
                }
            }
            */
            if(temp1.size()>temp2.size()){
                v.push_back(x);
                v.push_back(y);
                flag = 1;
                break;
            }


        }
        if(flag == 0){
            stringstream p(st);
            long long int z;
            p>>z;
            v.push_back(z);
        }

        //cout<<"Vector is:\n";
        cout<<v.size()<<endl;
        for(long long int z:v){
            cout<<z<<" ";
        }
        cout<<endl;
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

