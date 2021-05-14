#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string moves[n];
    for(int i=0;i<n;i++){
        cin >> moves[i];
    }
    bool done[n] = {false};
    string actualmove;
    cin >> actualmove;
    bool flag = true;
    // int i=0, j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j+moves[i].length() < actualmove.length();j++){
            string tmp = actualmove.substr(j, moves[i].length());
            if(tmp == moves[i]){
                done[i] = true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!done[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }

    return 0;
}