#include<bits/stdc++.h>
using namespace std;

vector <int> prod;
#define M 100000009
int k;
int check;

bool cmp(int a, int b){
    return a>b;
}

void findCombinationsUtil(int arr[], int index,
                       int num, int reducedNum)
{

    if (reducedNum < 0)
        return;


    if (reducedNum == 0)
    {
        int p=1;
        int flag=0;
        if(index==k){
            for (int i = 0; i < index; i++){
                if(arr[i]==arr[i+1]){
                    flag=1;
                    break;
                }
                p=((p%M)*((((arr[i]%M)*(arr[i]%M))%M)-(arr[i]%M)))%M;
            }
            if(flag!=1){
            /*    cout<<p<<"\n";*/
                prod.push_back(p);
                check=1;
            }

        }
/*        for (int i = 0; i < index; i++)
            cout << arr[i] << " ";
        cout << endl;
        */
        return;
    }


    int prev = (index == 0)? 1 : arr[index-1];


    for (int j = prev; j <= num ; j++)
    {

        arr[index] = j;


        findCombinationsUtil(arr, index + 1, num,
                                 reducedNum - j);
    }
}

void findCombinations(int n)
{

    int arr[n];


    findCombinationsUtil(arr, 0, n, n);
}


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

        int n;
        cin>>n>>k;
        findCombinations(n);
        if(check==1){
            sort(prod.begin(),prod.end(),cmp);
        cout<<*prod.begin()<<"\n";
        prod.clear();
        check=0;
        }
        else
            cout<<"-1\n";


    }


 /*   #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
