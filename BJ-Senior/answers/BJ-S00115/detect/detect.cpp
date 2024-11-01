#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
struct node{
    int x,y,id;
}p[N];
int cnt=0,ans1=0,ans2=0;
int T,n,m;
int trees[N];
double l,v;
double ac[N],v0[N],pos[N];
int plc[N],low[N];
bool cmp(node ax,node ay){
    return ax.x<ay.x||(ax.x==ay.x&&ax.id<ay.id);
    // return 0;
}
int st[N],top=0;
void push(int x){
    st[++top]=x;
}
void pop(){
    st[top]=0,top-=1;
}
int lowbit(int x){
    return x&(-x);
}
void modify(int x,int v){
    for(int i=x;i<=l;i+=lowbit(i)) trees[i]+=v;
}
int found(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)) sum+=trees[i];
    return sum;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T-->0){
        scanf("%d%d%lf%lf",&n,&m,&l,&v);
        l++;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf",&pos[i],&v0[i],&ac[i]);
            pos[i]+=1;
            int x2=1,y2=1;
            if(ac[i]<=0&&v0[i]<=v){
                x2=y2=int(l+20);
                p[++cnt].x=x2,p[cnt].y=y2,p[cnt].id=1;
                continue;
            }
            else if(ac[i]==0){
                x2=int(pos[i]),y2=int(l+20);
                p[++cnt].x=x2,p[cnt].y=y2,p[cnt].id=1;
                continue;
            }
            else{
                long double t=(v-v0[i])/ac[i];
                long double xx=v0[i]*t+0.5*ac[i]*t*t;
                long double ed=pos[i]+xx;
                if(ed>l) ed=l+20;
                if(ceil(ed)==floor(ed)){
                    if(ac[i]>0) ed=ed+1;
                    if(ac[i]<0) ed=ed-1;
                } 
                if(ac[i]>0) x2=int(ceil(ed)),y2=int(l+22);
                else x2=int(pos[i]),y2=int(ceil(ed));
                p[++cnt].x=x2,p[cnt].y=y2,p[cnt].id=1;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&plc[i]);
            plc[i]++;
            p[++cnt].x=plc[i],p[cnt].y=plc[i],p[cnt].id=2;
            modify(plc[i],1);
        }
        //for(int i=1;i<=cnt;i++) printf("%d %d %d\n",p[i].x,p[i].y,p[i].id);
        sort(p+1,p+1+cnt,cmp);
        //for(int i=1;i<=cnt;i++) printf("%d %d %d\n",p[i].x,p[i].y,p[i].id);
        for(int i=1;i<=cnt;i++){
            if(p[i].id==2) continue;
            if(found(p[i].y)-found(p[i].x-1)) ans1++;
            else p[i].y=l+20,p[i].x=l+20,p[i].id=1; 
        }
        sort(p+1,p+1+cnt,cmp);
        //for(int i=1;i<=cnt;i++) printf("%d %d %d\n",p[i].x,p[i].y,p[i].id);
        low[0]=0x3f3f3f3f;
        for(int i=1;i<=cnt;i++){
            // puts("qwq");
            if(p[i].id==1&&p[i-1].id==2) low[i]=p[i].y;
            else if(p[i].id==1) low[i]=min(low[i-1],p[i].y);
            else{
                low[i]=low[i-1];
                while(top!=0&&(p[i].y<=p[st[top]].y||p[i].y<=low[st[top]])){
                    low[i]=min(low[i],low[st[top]]);
                    pop();
                }
                while(top!=0&&st[top]==i-1&&p[i].y>=p[st[top]].y) pop(); 
                push(i);
                //cout<<top<<" qwq"<<endl;
            }
        }
        //for(int i=1;i<=cnt;i++) printf("%d\n",low[i]);
        if(ans1==0) ans2=m;
        else ans2=m-top;
        printf("%d %d\n",ans1,ans2);
        //init
        for(int i=1;i<=m;i++) modify(plc[i],-1);
        // for(int i=1;i<=cnt;i++) p[i].x=1,p[i].y=0,p[i].id=0;
        while(top>0) st[top]=0,top-=1;
        // for(int i=0;i<=n;i++) ac[i]=pos[i]=v0[i]=0;
        // for(int i=0;i<=m;i++) plc[i]=0;
        cnt=ans1=ans2=0;
    }
    return 0;
}