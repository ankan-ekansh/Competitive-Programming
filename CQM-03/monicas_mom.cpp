#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846
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
 
        int64_t n,r,R;
        int64_t tr;
        cin>>n>>R>>r;
        double a;
        double c = 0;
        int64_t x = 1;
        // tr = r-(x*r);
        // cout<<(pi*pow(R,2))-(double)n*pi*pow(r,2)<<"\n";
        // while(R-tr && ((pi*pow(R,2))-((double)n*pi*pow(r,2))>=0)){
        //     //double theta = (double)r/((double)(R-tr));
        //     double theta = (double)r/(double)(sqrt(pow((R-tr),2) - sqrt(pow(r,2))));
        //     cout<<theta<<"\n";
        //     a = atan(theta);
        //     cout<<a<<"\n";
        //     c+= (int64_t)(((double)2*(double)pi)/((double)a));
        //     x+=2;
        //     tr = (x*r);
        // }
        c = (double)(pi*pow(R,2))/(double)(pow(r,2)*sqrt(12));
        cout<<c<<"\n";
        // if((    (double)0.906 * pi * pow(R,2))  -   ((double)n * pi * pow(r,2))     >= 0){
        //     cout<<"YES\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }
        // cout<<c<<"\n";
        // if(c-n>=0){
        //     cout<<"YES\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }
        double rm = sqrt((double)n * pow(r,2) * (sqrt(12) / pi));
        cout<<rm<<"\n";
        if(R - rm >= 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}