#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nb = 0, nw = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'W'){
            nw++;
        }
        else{
            nb++;
        }
    }
    // cout << nb << " " << nw << "\n";
    if(nb % 2 != 0 && nw % 2 != 0){
        cout << "-1\n";
    }
    else if(nb % 2 == 0 && nw % 2 == 0){
        if(nb != nw){
            if(nb < nw){
                //cout << nb/2 << "\n";
                int no=0;
                vector<int> v;
                for(int i=0;i<n-1;i++){
                    if(s[i] == 'B'){
                        no++;
                        s[i] = 'W';
                        if(s[i+1] == 'B'){
                            s[i+1] = 'W';
                        }
                        else{
                            s[i+1] = 'B';
                        }
                        //cout << i+1 << " ";
                        v.push_back(i+1);
                    }
                }
                cout << no << "\n";
                for(int i=0;i<v.size();i++){
                    cout << v[i] << " ";
                }
            }
            else{
                // cout << nw/2 << "\n";
                int no=0;
                vector<int> v;
                for(int i=0;i<n-1;i++){
                    if(s[i] == 'W'){
                        no++;
                        s[i] = 'B';
                        if(s[i+1] == 'W'){
                            s[i+1] = 'B';
                        }
                        else{
                            s[i+1] = 'W';
                        }
                        // cout << i+1 << " ";
                        v.push_back(i+1);
                    }
                }
                cout << no << "\n";
                for(int i=0;i<v.size();i++){
                    cout << v[i] << " ";
                }
            }
        }
        else{
            // cout << nb/2 << "\n";
            int no=0;
            vector<int> v;
            for(int i=0;i<n-1;i++){
                if(s[i] == 'B'){
                    no++;
                    s[i] = 'W';
                    if(s[i+1] == 'B'){
                        s[i+1] = 'W';
                    }
                    else{
                        s[i+1] = 'B';
                    }
                    // cout << i+1 << " ";
                    v.push_back(i+1);
                }
            }
            cout << no << "\n";
            for(int i=0;i<v.size();i++){
                cout << v[i] << " ";
            }
        }

    }
    else if(nb % 2 == 0 && nw % 2 != 0){
        int no = 0;
        vector<int> v;
        for(int i=0;i<n-1;i++){
            if(s[i] == 'B'){
                no++;
                s[i] = 'W';
                if(s[i+1] == 'B'){
                    s[i+1] = 'W';
                }
                else{
                    s[i+1] = 'B';
                }
                v.push_back(i+1);
            }
        }
        cout << no << "\n";
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
    }
    else{
        int no = 0;
        vector<int> v;
        for(int i=0;i<n-1;i++){
            if(s[i] == 'W'){
                no++;
                s[i] = 'B';
                if(s[i+1] == 'B'){
                    s[i+1] = 'W';
                }
                else{
                    s[i+1] = 'B';
                }
                v.push_back(i+1);
            }
        }
        cout << no << "\n";
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
    }
    // cout << s << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}