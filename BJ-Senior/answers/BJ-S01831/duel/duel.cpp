#include <bits/stdc++.h>
using namespace std;

const long long MAXN=1e5+5;

int n,a[MAXN],b[MAXN],t[MAXN];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        t[lower_bound(b+1,b+1+m,a[i])-b]++;
    }
    for(int i=2;i<=m;i++){
        int a=t[i];
        for(int j=i-1;j;j--){
            int tmp=max(0,a-t[j]);
            t[j]-=min(t[j],a);
            a=tmp;
            if(!a)break;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans+=t[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
