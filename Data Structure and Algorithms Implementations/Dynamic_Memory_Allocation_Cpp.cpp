#include<bits/stdc++.h>
using namespace std;
int main(){
    int *p;
    p = new int;
    *p = 10;
    cout << *p << "\n";
    delete p;
    p = new int[3];
    p[0] = 1, p[1] = 2, p[2] = 3;
    cout << p[0] << " " << p[1] << " " << p[2] << "\n";
    cout << *p << " " << *(p+1) << " " << *(p+2) << "\n";
    delete[] p;
}