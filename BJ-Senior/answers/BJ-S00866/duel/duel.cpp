#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100000;i++){
        cnt=max(a[i],cnt);
    }
    cout<<cnt;
    return 0;
}
