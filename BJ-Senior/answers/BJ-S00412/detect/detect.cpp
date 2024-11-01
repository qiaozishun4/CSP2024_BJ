#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int T,n,m,L,V,chao[N],cnt,ans,ans1,ce[N];
int flag=0;
struct car{
    int num,v,a;
}c[N];

bool cmp(int a,int b){
    return a<b;
}

void svaq(){
    scanf("%d%d%d%d",&n,&m,&L,&V);
    for(int i=1;i<=n;i++){
        if(c[i].v>V && c[i].num<=ce[m]) ans++;
    }
    if(ans==0) ans1=m;
    else ans1=m-1;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(chao,0,sizeof(chao));
        cnt=0;
        ans=ans1=0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&c[i].num,&c[i].v,&c[i].a);
            if(c[i].a!=0) flag=1;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&ce[i]);
        }
        sort(ce+1,ce+n+1,cmp);
        if(flag==0) svaq();
        //else sv2();
        printf("%d %d\n",ans,ans1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
