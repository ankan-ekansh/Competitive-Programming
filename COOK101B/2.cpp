#include<bits/stdc++.h>
using namespace std;

const long long int M = 1000000007;
void rot(int a[], int n)
{
    int temp = a[0], i;
    for (i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    a[i] = temp;
}
//void leftrot(int a[], int d, int n)
//{
//    for (int i = 0; i < d; i++)
//       rot(arr, n);
//}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int test;
    cin>>test;
    while(test--){

        int n;
        cin>>n;
        int t = n;
        int nd=0;
        long long int yn=0;
        int a[100000];
        while(t>0){
            nd++;
            t/=10;
        }
        int k=0;
        t=n;
        for(int i=nd;i>0;i--){

            a[i-1]=t%10;
            t=t/10;
            k++;

//            a[k++]=t/(pow(10,i-1));
//            int p=pow(10,i-1);
//            t=t%(p);
        }
//        for (int i = 0; i < k; i++)
//                cout << a[i] << " ";
//           cout<<endl;
        long long int prevrot=n;
        long long int currentrot=0;
        yn = prevrot;
        for(int i=1;i<nd;i++){
            rot(a, k);
//            for (int i = 0; i < k; i++)
//                cout << a[i] << " ";
//            cout<<endl;
            int x=10;
            for(int j=0;j<k;j++){
                currentrot=(currentrot*(x))+a[j];
            }
//            cout<<"Currentrot "<<currentrot<<endl;
            long long int z=1;;
            for(int l=0;l<nd;l++){
                z=(z*10);
            }
            yn = (((yn * z)%M)+(currentrot))%M;
//            cout<<"No "<<yn<<endl;
            prevrot=currentrot;
            currentrot = 0;
        }
        cout<<yn<<endl;





    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

