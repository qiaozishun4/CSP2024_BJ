#include<bits/stdc++.h>

#define MAXN 100005

int n;
int r[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    std::cin>>n; for(int i=1;i<=n;i++) std::cin>>r[i];
    std::sort(r+1,r+n+1);
    int p=1;
    for(int i=1;i<=n;i++){
        if(p<i&&r[p]<r[i]) p++;
    }
    std::cout<<n-p+1<<'\n';

    return 0;
}