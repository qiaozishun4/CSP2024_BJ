#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,nmin=100005,nmax=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        nmin=min(a,nmin);
        nmax=max(a,nmax);
        b[a]++;
    }
    for(int i=nmin+1;i<=nmax;i++)
        if(b[i]<=b[i-1])b[i]=b[i-1];
    printf("%d",b[nmax]);
    return 0;
}
