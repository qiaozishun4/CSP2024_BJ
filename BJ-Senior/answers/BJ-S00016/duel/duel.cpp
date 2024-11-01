#include<bits/stdc++.h>
using namespace std;
int n,a[100010],maxn,sum;
int b[100010];
int c[100010],cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=maxn;i++){
        if(b[i]==0){
            continue;
        }
        c[++cnt]=b[i];
    }
    for(int i=1;i<cnt;i++){
        sum+=min(c[i],c[i+1]);
    }
    cout<<n-sum;
    return 0;
}
