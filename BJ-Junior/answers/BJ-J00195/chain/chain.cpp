#include<bits/stdc++.h>
using namespace std;
struct tpt{
    int r,c;
}a[100005];
bool cmp(struct tpt a,struct tpt b){
    return a.r<b.r;
}
struct plc{
    int st,tm;
};
struct que{
    int fpt,lpt,rd[1000005];
    struct plc dt[1000005];
}lt;
void qpop(){
    lt.fpt=(lt.fpt+1)%1000001;
}
void qpsh(int rod,struct plc idt){
    lt.lpt=(lt.lpt+1)%1000001;
    lt.rd[lt.lpt]=rod;
    lt.dt[lt.lpt]=idt;
}
struct plc dtop(){
    return lt.dt[lt.fpt];
}
int rtop(){
    return lt.rd[lt.fpt];
}
bool nt[200010];
int T,n,k,q,l[200010];
vector<struct plc> wd[200010];
void bfs(){
    sort(a+1,a+q,cmp);
    int mr=a[q].r;
    int rnw=0,apt=1;
    struct plc now;
    now.st=0;now.tm=1;
    qpsh(0,now);
    while(rnw<=mr){
        int flag=false;
        for(int i=lt.fpt;;i=(i+1)%1000001){
            if(rtop()>rnw){
                if(rnw==a[apt].r){
                    printf("%d\n",flag);
                    apt++;
                    flag=false;
                }
                for(int p=0;p<=200005;p++) nt[p]=false;
                break;
            }
            now=dtop();
            if(rnw==a[apt].r&&now.tm==a[apt].c) flag=true;
            
        }
        rnw++;
    }
}
int main(){
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i],j++){
                int wj;struct plc tem;
                scanf("%d",&wj);
                tem.st=i;tem.tm=j;
                wd[wj].push_back(tem);
            }
        }
        for(int i=1;i<=q;i++) scanf("%d%d",&a[i].r,&a[i].c);
        bfs();
    }
    return 0;
}
