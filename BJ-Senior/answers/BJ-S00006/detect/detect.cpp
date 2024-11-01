#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define int long long
using namespace std;
int t;
int n,m,len,v;
struct node{
    int d,v,a;
}c[100005];
int p[100005];
struct nodev{
    int a,b;
}il[100005];
int k;
bool cmp(nodev x,nodev y){
    return x.b<y.b;
}
bool vis[100005];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        k=0;
        //memset(vis,false,sizeof(vis));
        scanf("%lld%lld%lld%lld",&n,&m,&len,&v);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
        }
        sort(p+1,p+m+1);
        int ans1=0;
        bool flag1=false,flag2=false;
        for(int i=1;i<=n;i++){
            if(c[i].a>0){
                flag1=true;
                int tmp,pos;
                if(c[i].v>v){
                    pos=lower_bound(p+1,p+m+1,c[i].d)-p;
                    if(pos<=m&&p[pos]>=c[i].d){
                        ans1++;
                        il[++k].a=pos,il[k].b=m;
                    }
                    continue;
                }
                double tp=(v*v-c[i].v*c[i].v)*1.0/(2*c[i].a)+c[i].d;
                tmp=tp+1;
                pos=lower_bound(p+1,p+m+1,tmp)-p;
                if(pos<=m&&p[pos]>=tmp){
                    ans1++;
                    il[++k].a=pos,il[k].b=m;
                }
            }else if(c[i].a==0){
                flag2=true;
                if(c[i].v<=v)continue;
                int pos=lower_bound(p+1,p+m+1,c[i].d)-p;
                if(pos<=m&&p[pos]>=c[i].d){
                    ans1++;
                    il[++k].a=pos,il[k].b=m;
                }
            }else{
                flag1=flag2=true;
                if(c[i].v<=v)continue;
                int tmp;
                double tp=(c[i].v*c[i].v-v*v)*1.0/(-2*c[i].a)+c[i].d;
                if(tp==(int)(tp))tmp=tp-1;
                else tmp=tp;
                int pos1=lower_bound(p+1,p+m+1,c[i].d)-p;
                int pos2=upper_bound(p+1,p+m+1,tmp)-p;
                pos2--;
                if(pos1<=m&&pos2<=m&&pos1<=pos2&&p[pos2]<=tmp&&p[pos1]>=c[i].d){
                   // printf("i:%lld tmp:%lld\n",i,tmp);
                    ans1++;
                    il[++k].a=pos1,il[k].b=pos2;
                }
            }
        }
        printf("%lld ",ans1);
        if(!flag1||!flag2){
            if(ans1)printf("%lld\n",m-1);
            else printf("%lld\n",m);
            continue;
        }
        sort(il+1,il+k+1,cmp);
        int num=0;
        for(int i=1;i<=k;i++){
            if(vis[i]){
                vis[i]=false;
                continue;
            }
            num++;
            for(int j=i+1;j<=k;j++)if(il[j].a<=il[i].b)vis[j]=true;
        }
        printf("%lld\n",m-num);
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
