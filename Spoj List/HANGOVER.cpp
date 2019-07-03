#include<bits/stdc++.h>
using namespace std;
bool isequal(float a, float b, float epsi = 0.0001f){
	return (fabs(a - b) < epsi);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 1;
    float a[300];
	float ans = 0.0;
	while((5.20 - ans) > 0.0f){
		ans+=(float)1/(float)(i+1);
		//cout<<i<<" "<<ans<<"\n";
        a[i] = ans;
		i++;
	}

    while(1){
        float c;
        cin>>c;
        if(isequal(c, 0.00)){
            break;
        }
        else{
            for(int i=1;i<=276;i++){
                if(a[i] > c){
                    cout<<i<<" card(s)\n";
                    break;
                }
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}