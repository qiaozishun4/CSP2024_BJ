#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define ll long long
using namespace std;

const int maxn=2e5+5;

int n,a[maxn];

struct block{
    int val,len;
}c[maxn];
int tot;

int main(){
    fin("duel.in");
    fout("duel.out");
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);


    int lst=1;
    for (int i=1;i<=n;i++){
        while (i<=n && a[i+1]==a[lst]) i++;
        c[++tot]=(block){a[lst],i-lst+1};
        lst=i+1;
    }

    int rem=0,ans=0;
    for (int i=1;i<=tot;i++){
        int res=max(0,c[i].len-rem);
        ans+=res;
        rem+=res;
    }

    printf("%d\n",ans);
    return 0;
}
