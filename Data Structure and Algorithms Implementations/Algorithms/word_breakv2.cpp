#include<iostream>
using namespace std;
bool isValidPref(string word){
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
void wordBreak(string s, string res){
    if(!s.length()){
        cout << res << "\n";
        return;
    }
    for(int i=1;i<=s.length();i++){
        if(isValidPref(s.substr(0, i))){
            string tmp = res + s.substr(0, i) + " ";
            wordBreak(s.substr(i, s.length()-i), tmp); 
        }
    }
}
int main(){

    string s = "iloveicecreamandmango";
    wordBreak(s, "");
    return 0;
}