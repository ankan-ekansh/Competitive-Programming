#include<iostream>
using namespace std;
bool contains(string word){
    string dict[] = {"mobile","samsung","sam","sung", 
                            "man","mango", "icecream","and", 
                            "go","i","love","ice","cream"};
    int n = sizeof(dict)/sizeof(dict[0]);
    for(int i=0;i<n;i++){
        if(dict[i] == word){
            return true;
        }
    }
    return false;
}
void wordBreak(string s, int n, string res){
    for(int i=1;i<=n;i++){
        string pref = s.substr(0, i);
        if(contains(pref)){
            if(i == n){
                res += pref;
                cout << res << "\n";
                return;
            }
            wordBreak(s.substr(i, n-i), n-i, res + pref + " ");
        }
    }
}
int main(){

    string s = "iloveicecreamandmango";
    wordBreak(s, s.length(), "");
    return 0;
}