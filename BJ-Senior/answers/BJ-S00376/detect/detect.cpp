#include<bits/stdc++.h>
using namespace std;
const int eps=1e-7;

struct Car{
    int st,v,a;
    double en;
    double limitst,limiten;
};

int lowbit(int x){
    return x&-x;
}


int n,m,L,V,cnt;
Car c[100002],li[100002];
double p[100002];
bool flag_A=1,vis[100002];

void Find(double s1,double s2,int i){

    int pos1=lower_bound(p+1,p+m+1,s1)-p;
    int pos2=upper_bound(p+1,p+m+1,s2)-p;
    if(pos1>0&&pos1<pos2){
        li[++cnt]=c[i];
        li[cnt].limitst=s1;
        li[cnt].limiten=s2;
    }

}

bool cmp(Car x,Car y){
    return x.limiten<y.limiten;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        flag_A=1;
        cnt=0;
        scanf("%d %d %d %d",&n,&m,&L,&V);
        for(int i=1;i<=n;++i){
            scanf("%d %d %d",&c[i].st,&c[i].v,&c[i].a);
            if(c[i].a!=0) flag_A=0;
            if(c[i].a<0){
                c[i].en=min(L*1.0,(c[i].v*c[i].v)*(-0.5)/c[i].a);
            }
            else{
                c[i].en=L;
            }
        }
        for(int i=1;i<=m;++i){
            int x;
            scanf("%d",&x);
            p[i]=x;
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            int v=c[i].v;
            double s;
            if(v<=V){
                if(c[i].a<=0)continue;
                s=(V*V-v*v)*1.0/2/c[i].a;
                if(s+c[i].st>(c[i].en)) continue;
                Find(s+c[i].st,c[i].en,i);
            }
            else if(v>V){
                if(c[i].a>=0) {
                    Find(c[i].st,c[i].en,i);
                }
                else{
                    s=(V*V-v*v)*1.0/2/c[i].a;
                    Find(c[i].st,s+c[i].st,i);
                }
            }
        }
        int ans=0;
        memset(vis,0,sizeof(vis));
        priority_queue<int> q,q2;
        sort(li+1,li+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            double s1=li[i].limitst;
            double s2=li[i].limiten;
            //printf("%.2lf %.2lf\n",s1,s2);
            int pos1=lower_bound(p+1,p+m+1,s1)-p;
            int pos2=upper_bound(p+1,p+m+1,s2)-p;
            bool flag=0;
            for(int j=pos1;j<pos2;j++){
                if(vis[j]){
                    flag=1;
                    break;
                }
            }
            while(!q.empty()){
                int x=q.top();q.pop();
                if(pos1<=x&&x<pos2){
                    flag=1;
                    q2.push(x);
                    break;
                }
                q2.push(x);
            }
            while(!q2.empty()){
                int x=q2.top();
                q2.pop();
                q.push(x);
            }
            if(flag) continue;
            else{
                vis[pos2-1]=1;
                q.push(pos2-1);
                ans++;
            }
        }
        if(cnt==0) ans=n;
        if(cnt==1) ans=n-1;
        printf("%d %d\n",cnt,n-ans);
    }
    return 0;
}
