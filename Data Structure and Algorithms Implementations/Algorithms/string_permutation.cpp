#include<iostream>
#include<string>
using namespace std;
void permute(string s, int l, int r){
    if(l == r){
        cout << s << "\n";
        return;
    }
    for(int i=l;i<=r;i++){
        swap(s[i], s[l]);
        permute(s, l+1, r);
        swap(s[i], s[l]);
    }
}
int main(){

    string s;
    cin >> s;
    permute(s, 0, s.length()-1);
    return 0;
}