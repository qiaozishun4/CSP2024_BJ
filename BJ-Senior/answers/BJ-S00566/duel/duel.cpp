#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,r[100005],st[100005],h=1,t;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> r[i];
    }
    sort(r+1,r+n+1);
    for(int i = 1;i <= n;i++){
        if(h<=t && st[h]<r[i]) h++;
        st[++t]=r[i];
    }
    cout << t-h+1;
    return 0;
}