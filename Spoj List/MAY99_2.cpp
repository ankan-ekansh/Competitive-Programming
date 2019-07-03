#include<bits/stdc++.h>
using namespace std;
long long longlog(long long base, long long x){
    return (long long)(log(x) / log(base));
}
long long power(long long base, long long exponent){
    if(exponent == 0){
        return 1;
    }
    else if(exponent == 1){
        return base;
    }
    else{
        long long x = power(base, exponent/2);
        if(exponent % 2 == 0){
            return x*x;
        }
        else{
            return base*x*x;
        }
    }
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
 
        long long n;
        cin>>n;
        char a[5]={'m', 'a', 'n', 'k', 'u'};
        long long temp = n;
        char s[1000000];
        long long i = 0;
        while(temp > 0){
            long long x = temp % 5;
            //cout<<x<<" ";
            //cout<<"temp:"<<temp<<"\n";
            //cout<<"x:"<<x<<"\n";
            if(x == 0){
                //cout<<a[x]<<" ";
                char c = 'u';
                s[i++]=c;
                temp=(temp/5) - 1;
            }
            else{
                //cout<<a[x-1]<<" ";
                //s[i++]=a[x];
                //char c = (x-1) + 'a';
                //s[i++]=a[c - 97];
                s[i++]=a[x-1];
                temp = temp/5;
            }
            //cout<<temp<<"\n";
            //cout<<s<<"\n";
        }
        s[i]='\0';
        reverse(s, s+strlen(s));
        cout<<s<<"\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}