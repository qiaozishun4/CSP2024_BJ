#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct car{
    int d,v,a;
    bool flag;
}c[100010];
struct nod{
    int p;
    bool check;
    vector<int>c;
}p[100010];
bool cmp(nod a,nod b){
    return a.p<b.p;
}
bool check(int i,nod b,int V2){
    if(2*c[i].a*b.p+c[i].v*c[i].v>V2){
        b.c.push_back(i);
        return 1;
    }
}
void solve(){
    int n,m,L,V,ans1=0,ans2=0;
    scanf("%d%d%d%d",&n,&m,&L,&V);
    ans2=m;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
    for(int i=1;i<=m;i++)
        scanf("%d",&p[i].p);
    sort(p+1,p+1+m,cmp);
    int V2=V*V;
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=m;j++){
            if(check(i,p[j],V2))flag=1;
        }
        if(flag)ans1++;
        c[i].flag=flag;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;i++){
            if(p[i].c==p[j].c)ans2--;
        }
    }
    printf("%d %d\n",ans1,ans2);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
