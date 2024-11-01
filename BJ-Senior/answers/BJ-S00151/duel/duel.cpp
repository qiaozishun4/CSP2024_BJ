#include<bits/stdc++.h>
using namespace std;
int n;
int r[100010];
bool cmp(int x, int y){
    return x>y;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1, r+n+1, cmp);
    int x=n, y=n;
    while(r[y]==r[x]){
        y--;
    }
    while(r[y]>r[x]){
        y--;
        x--;
    }
    cout<<x;
    return 0;
}