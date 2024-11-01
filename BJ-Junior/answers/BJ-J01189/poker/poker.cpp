#include <bits/stdc++.h>
using namespace std;
int n;
bool maps[5][15];
int ans=52;
int list2(char a){
    if(a=='D')return 1;
    if(a=='C')return 2;
    if(a=='H')return 3;
    if(a=='S')return 4;
    return 0;
}
int list1(char a){
    if(a=='A')return 1;
    if(a=='T')return 10;
    if(a=='J')return 11;
    if(a=='Q')return 12;
    if(a=='K')return 13;
    return int(a-'0');
}
void solve(int a,int b){
    if(!maps[a][b]){
        ans--;
        maps[a][b]=true;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w"stdout);
    cin >> n;
    while(n--){
        char a,b;
        cin >> a >> b;
        solve(list2(a),list1(b));
    }
    cout << ans;
    return 0;
}