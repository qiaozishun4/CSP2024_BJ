#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=1e6+10;
struct car
{
    int d,v,a;
}c[N];
struct speed
{
    int first,last;
}ne[N];
int p[N],sum[M];
int n,m,l,v0,T,cnt;
priority_queue <speed> q;

bool operator < (speed x,speed y)
{
    return x.last>y.last;
}

bool cmp(speed x,speed y)
{
    return x.first<y.first;
}

bool cmp2(speed x,speed y)
{
    return x.last>y.last;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&l,&v0);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        for(int i=1;i<=m;i++) scanf("%d",&p[i]);
        //speed
        cnt=0;
        for(int i=0;i<=l;i++) sum[i]=0;
        for(int i=1;i<=m;i++) sum[p[i]]++;
        for(int i=1;i<=l;i++) sum[i]=sum[i-1]+sum[i];
        int v,a,d,start,last;long double x;
        for(int i=1;i<=n;i++){
            v=c[i].v,a=c[i].a,d=c[i].d;
            if(v>v0 && a>=0) start=d,last=l;
            else if(v<=v0 && a<=0) continue;
            else{
                x=(long double)(1ll*v0*v0-1ll*v*v)/(2*a);
                if(v>v0 && a<0){
                    start=d;
                    if(x==(int)(x)) x--;
                    else x=(int)(x);
                    last=min(d+(int)x,l);
                }
                else if(v<=v0 && a>0){
                    last=l;
                    if(x==ceil(x)) x++;
                    else x=ceil(x);
                    start=min(d+(int)x,l+1);
                }
            }
            if(start>0 && sum[last]-sum[start-1]>0) ne[++cnt]=(speed){sum[start-1]+1,sum[last]};
            else if(start==0 && sum[last]) ne[++cnt]=(speed){1,sum[last]}; //?
            //cout<<i<<" "<<start<<" "<<last<<endl;
        }
        //cout<<n<<endl;
        printf("%d ",cnt);
        if(cnt==0) {printf("%d\n",m);continue;}
        int ans=0,ans2=0;
        sort(ne+1,ne+cnt+1,cmp);
        //cout<<ne[1].first<<" "<<ne[1].last<<endl;
        for(int i=1;i<=cnt;i++){
            //cout<<ne[i].first<<" "<<ne[i].last<<endl;
            if(q.size() && q.top().last<ne[i].first){
                while(q.size()) q.pop();
                ans++;
            }
            q.push(ne[i]);
        }
        while(q.size()) q.pop();
        ans++;/*
        sort(ne+1,ne+cnt+1,cmp2);
        for(int i=1;i<=cnt;i++){
            if(q.size() && q.top().last>ne[i].last){
                while(q.size()) q.pop();
                ans2++;
            }
            swap(ne[i].first,ne[i].last);
            q.push(ne[i]);
        }
        while(q.size()) q.pop();
        ans2++;*/
        printf("%d\n",m-max(ans,ans2));
    }
    return 0;
}
