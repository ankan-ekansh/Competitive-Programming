#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int n;
long int arr[100000];
vector<long int> v1,v2;
long int power(long int a, long int b, int p){
    int r=1;
    a=a%p;
    while(b>0){
        if(b & 1){
            r=(r*a)%p;
        }
        b=b>>1;
        a=(a*a)%p;
    }
    return r;
}


void combi(long int arr[],long int temp[], int start, int end,
                     int index);
void assigncombi(long int arr[], int n){
    long int temp[2];
    combi(arr, temp, 0, n-1, 0);
}
void combi(long int arr[],long int temp[], int start, int end,int index){
    if (index == 2){
        for (int j=0; j<2; j++){
            v1.push_back(temp[0]);
            v2.push_back(temp[1]);
        }
        return;
    }
    for (int i=start; i<=end && end-i+1 >= 2-index; i++){
        temp[index] = arr[i];
        combi(arr, temp, i+1, end, index+1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a;
    cin>>n>>a;
    long int amt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    assigncombi(arr, n);
    for(int i=0;i<v1.size();i++){
        amt+=(power((abs(v1[i]%M-v2[i]%M)%M),a,M));
    }
    cout<<amt;


//    #ifndef ONLINE_JUDGE
//        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//    #endif
    return 0;
}

