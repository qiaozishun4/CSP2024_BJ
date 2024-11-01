#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N],t;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>a[t+1])t++;
    }
    cout<<n-t;
    return 0;
}