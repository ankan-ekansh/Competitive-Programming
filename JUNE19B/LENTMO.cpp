#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
map<ull, ull> vis;
map<ull, ull> m;
map<ull, ull> ind;
vector<ull> lows,highs;
vector<pair<long long, ull>> diff;
ull sumAll(ull a[], ull n){
    ull sum = 0;
    for(ull i=0;i<n;i++){
        if(ind[a[i]] == 2){
            sum+=a[i];
        }
        else{
            sum+=m[a[i]];
        }
    }
    return sum;
}
ull sumSome(ull a[], ull n, ull l){
    ull sum = 0;
    bool found = false;
    for(ull i=0;i<n;i++){
        if(a[i] == l && found == false){
            sum+=l;
            found = true;
        }
        else{
            if(ind[a[i]] == 2){
                sum+=a[i];
            }
            else{
                sum+=m[a[i]];
            }
        }
        //cout<<"Sum till now: "<<sum<<"\n";
    }
    return sum;
}
ull sumConditionOdd(ull a[], ull n, ull lc, ull hc, ull k){
    if(k == n){
        ull sum1 = 0, sum2 = 0;
        for(ull i=0;i<n;i++){
            sum1+=a[i];
            sum2+=m[a[i]];
        }
        ull sum = max(sum1, sum2);
        return sum;
    }
    //else if(k == (n-1)){
    else{
        if(hc % 2 != 0){
            ull sum = 0;
            for(ull i=0;i<n;i++){
                if(ind[a[i]] == 2){
                    sum+=a[i];
                }
                else{
                    sum+=m[a[i]];
                }
            }
            return sum;
        }
        else{
            // ull sum = 0;
            // bool found = false;
            // for(ull i=0;i<n;i++){
            //     if(a[i] == *(lows.begin()) && !found){
            //         sum+=*(lows.begin());
            //         found = true;
            //     }
            //     else{
            //         if(ind[a[i]] == 2){
            //             sum+=a[i];
            //         }
            //         else{
            //             sum+=m[a[i]];
            //         }
            //     }
            // }
            // return sum;
            ull l = (*(diff.begin())).second;
            ull sum = sumSome(a, n, l);
            return sum;
        }
    }
}
ull sumConditionEven(ull a[], ull n, ull lc, ull hc, ull k){
    if(k == n){
        ull sum1 = 0, sum2 = 0;
        for(ull i=0;i<n;i++){
            sum1+=a[i];
            sum2+=m[a[i]];
        }
        ull sum = max(sum1, sum2);
        return sum;
    }
    //if(k == (n-1)){
    else{
        if(hc % 2 != 0){
            ull sum = 0;
            for(ull i=0;i<n;i++){
                if(ind[a[i]] == 2){
                    sum+=a[i];
                }
                else{
                    sum+=m[a[i]];
                }
            }
            return sum; 
        }
        else{
            ull l = (*(diff.begin())).second;
            ull sum =  sumSome(a, n, l);
            return sum;
        }
    }
}
ull odd(ull lc, ull hc, ull k, ull a[]){    //when lc is odd
    if(k == (hc + lc -1)){
        ull sum = sumConditionOdd(a, hc+lc, lc, hc, k);
        return sum;
    }
    else if(k == (hc + lc)){
        ull sum = sumConditionOdd(a, hc+lc, lc, hc, k);
        return sum;
    }
    else if(k == 1){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    else if(k == lc){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    else if(k % 2 != 0){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    //if(k % 2 == 0){
    else{
        ull l = (*(diff.begin())).second;
        ull sum = sumSome(a, hc+lc, l);
        return sum;
    }
}
ull even(ull lc, ull hc, ull k, ull a[]){   //when lc is even
    if(k == (lc+hc)){
        ull sum = sumConditionEven(a, hc+lc, lc, hc, k);
        return sum;
    }
    else if(k == (lc+hc-1)){
        ull sum = sumConditionEven(a, hc+lc, lc, hc, k);
        return sum;
    }
    else if(k == 1){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    else if(k == lc){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    else if(k <= (hc + (lc>>1))){
        ull sum = sumAll(a, hc+lc);
        return sum;
    }
    //if(k > (hc + (lc>>1))){
    else{
        if(k % 2 == 0){
            ull sum = sumAll(a, hc+lc);
            return sum;
        }
        else{
            ull l = (*(diff.begin())).second;
            ull sum = sumSome(a, hc+lc, l);
            return sum;
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
    ull t;
    cin>>t;
    while(t--){
 
        ull n,k,x;
        cin>>n;
        ull a[n];
        for(ull i=0;i<n;i++){
            cin>>a[i];
            vis[a[i]]++;
        }
        cin>>k;
        cin>>x;
        ull l = 0, h = 0;
        for(ull i=0;i<n;i++){
            ull var = a[i];
            m[var]=var^x;
            if(var < (var^x)){
                l++;
                lows.push_back(var);
                ind[var]=1;
            }
            else{
                h++;
                highs.push_back(var);
                ind[var]=2;
            }
            if(vis[var^x])
                m[var^x]=var;
        }
        //sort(lows.begin(),lows.end(),greater<ull>());
        //sort(highs.begin(),highs.end(),greater<ull>());

        for(auto i=lows.begin();i!=lows.end();i++){
            diff.push_back(make_pair((m[*i] - *i), *i));
            //diff[*i - m[*i]] = *i;
        }

        sort(diff.begin(), diff.end());
        // for(auto i=diff.begin();i!=diff.end();i++){
        //     cout<<(*i).first<<" "<<(*i).second<<"\n";
        // }
        // cout<<"\n";
        // for(auto i = m.begin();i!=m.end();i++){
        //     cout<<(*i).first<<" "<<(*i).second<<"\n";
        // }
        // cout<<"L: "<<l<<" H: "<<h<<"\n";
        // for(auto i=lows.begin();i!=lows.end();i++){
        //     cout<<*i<<" ";
        // }
        // cout<<"\n";
        // for(auto j=highs.begin();j!=highs.end();j++){
        //     cout<<*j<<" ";
        // }
        // cout<<"\n";
        // cout<<"\n";
        if(l % 2 == 0){
            cout<<even(l, h, k, a)<<"\n";
        }
        else{
            cout<<odd(l, h, k, a)<<"\n";
        }
        m.clear();
        vis.clear();
        ind.clear();
        lows.clear();
        highs.clear();
        diff.clear();
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}