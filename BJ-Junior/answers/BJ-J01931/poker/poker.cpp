#include<bits/stdc++.h>
using namespace std;
map<pair<char, char>, int> mp;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%d", &n);
    string s;
    for(int i = 1;i <= n;i++){
        cin>>s;
        mp[make_pair(s[0], s[1])]++;
    }
    printf("%d\n", 52 - (int)mp.size());
    return 0;
}
/*
cd ~/GJH/poker && g++ poker.cpp && ./a.out 

4
DQ
H3
DQ
DT
*/