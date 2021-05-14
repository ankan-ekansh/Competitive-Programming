#include<iostream>
using namespace std;
int main(){

    string pref;
    string sentence;
    // cin >> pref;
    getline(cin, pref);
    // cin >> sentence;
    // cin.get();
    getline(cin, sentence);
    for(int i=0;i+pref.length()<sentence.length();){
        string tmp = sentence.substr(i, pref.length());
        // cout << tmp << "\n";
        int j = i;
        if(tmp == pref){
            while(j < sentence.length() && sentence[j] != ' '){
                j++;
            }
            cout << sentence.substr(i, j-i) << "\n";
        }
        i = j+1;
    }
    return 0;
}