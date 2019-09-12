    #include<bits/stdc++.h>
    using namespace std;
    bool prime[10000];
    void sieve(){
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for(int i=2;i*i<=9999;i++){
            if(prime[i]){
                for(int j=i*i;j<=9999;j+=i){
                    prime[j] = false;
                }
            }
        }
    }
    int aToNum(int a[]){
        int n = 0;
        n+=a[3];
        n+=(a[2] * 10);
        n+=(a[1] * 100);
        n+=(a[0] * 1000);
        return n;    
    }
    void numToA(int n, int a[]){
        a[3] = n % 10;
        a[2] = (n/10) % 10;
        a[1] = (n/100) % 10;
        a[0] = (n/1000) % 10;
    }
    int bfs(int src, int dest){
        queue<int> q;
        int dist[10000];
        memset(dist, -1, sizeof(dist));
        // vis[src] = true;
        q.push(src);
        int a[4];
        // numToA(src, a);
        // numToA(src, b);
        // cout << src << "\n";
        dist[src] = 0;
        while(!q.empty()){
            int curr = q.front();
            // q.pop();
            // cout << curr << "\n";
            for(int k=3;k>=0;k--){
                numToA(curr, a);
                // cout << curr << "\n";
                // cout << a[0] << a[1] << a[2] << a[3] << "\n";
                for(int i=0;i<=9;i++){
                    a[k] = i;
                    // cout << a[0] << a[1] << a[2] << a[3] << "\n";
                    int temp = aToNum(a);
                    // cout << temp << "\n";
                    if((prime[temp] == true) && (dist[temp] == -1) && (temp >= 1000)){
                        // cout << temp << "\n";
                        dist[temp] = dist[curr] + 1;
                        q.push(temp);
                    }
                }
            }
            q.pop();
        }
        return dist[dest];
    }
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "rt", stdin);
            freopen("output.txt", "wt", stdout);
        #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t;
        cin>>t;
        while(t--){
     
            int l, r;
            cin >> l >> r;
            // int a[4], b[4];
            // numToA(l, a);
            // numToA(r, b);
            sieve();
            // bool vis[10000] = {false};
            int ans = bfs(l, r);
            if(ans == -1){
                cout << "Impossible\n";
            }
            else{
                cout << ans <<"\n";
            }
     
            // for(int i=2;i<=99;i++){
            //     if(prime[i]){
            //         cout<<i<<"\n";
            //     }
            // }
     
            // for(int d : a){
            //     cout << d ;
            // }
            // cout << "\n";
            // for(int d : b){
            //     cout << d ;
            // }
            // cout << "\n";
            // cout << aToNum(a) << "\n";
            // cout << aToNum(b) << "\n";
        }
        #ifndef ONLINE_JUDGE
            cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
        #endif
        return 0;
    } 