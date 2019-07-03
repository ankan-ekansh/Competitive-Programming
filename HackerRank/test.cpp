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
  	cin.ignore();
  	while(t--){
  		string ct;
  		vector<long long int> v;
  		getline(cin,ct);
  		//cout<<ct<<endl;
  		for(auto i=ct.begin();i!=ct.end();i++){
  			long long int l = ct.size();
  			//cout<<(l)<<endl;
  			string temp1 = "";
  			string temp2 = "";
  			temp1 = ct.substr(0,i-ct.begin());
  			temp2 = ct.substr(i-ct.begin(),l-1);
  			//cout<<temp1<<endl;
  			cout<<"temp1:"<<temp1<<" temp2:"<<temp2<<endl;
            long long int x;
            if(temp1.size()!=0){
                    stringstream z(temp1);
                    z>>x;
                    cout<<"x:"<<x<<endl;
            }

  			if(temp1.size() == temp2.size()){
                if(temp2.size()!=0){
                    stringstream zz(temp2);
                    long long int y;
                    zz>>y;
                    cout<<"y:"<<y<<endl;
                    if(x>y){
                        v.push_back(x);
                        ct = temp2;
                    }
                }
  			}
  			if(temp1.size() > temp2.size()){
  				v.push_back(x);
  				ct = temp2;
  			}

  		}

  		cout<<v.size()<<endl;
  		for(auto i = v.begin();i!=v.end();i++){
  			cout<<*i<<" ";
  		}
  		cout<<"\n";
  	}
//    #ifndef ONLINE_JUDGE
//        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//    #endif
    return 0;
}


