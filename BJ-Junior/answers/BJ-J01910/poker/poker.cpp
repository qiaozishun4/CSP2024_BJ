#include <bits/stdc++.h>
using namespace std;
int ids[1000]; // three digit id
int name2id(string s){
    if(s.size() != 2){
        return -1; // Not good
    }
    char f = s[0], l = s[1]; // color and number
    int a = 0, b = 0;
    switch(f){
        case 'D':a = 1;break;
        case 'C':a = 2;break;
        case 'H':a = 3;break;
        case 'S':a = 4;break;
        default :a = 5;break;
    }
    if((a == 5) || (a == 0)){
        return -1;
    }
    switch(l){
        case 'A':b = 1; break;
        case '2':b = 2; break;
        case '3':b = 3; break;
        case '4':b = 4; break;
        case '5':b = 5; break;
        case '6':b = 6; break;
        case '7':b = 7; break;
        case '8':b = 8; break;
        case '9':b = 9; break;
        case 'T':b = 10;break;
        case 'J':b = 11;break;
        case 'Q':b = 12;break;
        case 'K':b = 13;break;
        default :b = 14;break;
    }
    if((b == 14) || (b == 0)){
        return -1;
    }
    return a * 100 + b; // Hash
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        int myid = name2id(s);
        if(myid == -1){
            continue;
        }
        ids[myid] = 1;
    }
    for(int i = 0;i < 1000;i++){
        cnt += ids[i];
    }
    cout << 52 - cnt;
    return 0;
}
