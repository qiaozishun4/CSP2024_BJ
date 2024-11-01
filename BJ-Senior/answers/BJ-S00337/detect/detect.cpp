#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int M = 1e5+10;
int t,n,m,l,v1,d,a1,v0,p[M],k,c[M];
bool f[M];
priority_queue<PII,vector<PII>,greater<PII>> q;
struct node{
    int x,y;
    bool r;
}a[M];
struct st{
    int idx,num;
}s[M];
void add(int x,int y){
    //cout<<"#"<<" "<<x<<" "<<y<<endl;
    a[++k]={x,y};
}
bool cmp(st s1,st s2){
    return s1.num>s2.num;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        k=0;
        memset(f,false,sizeof(f));
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v1);
        for(int i = 1;i <= n;i++){
            scanf("%lld%lld%lld",&d,&v0,&a1);
            if(a1==0){
                if(v0>v1) add(d,l);
            }else if(a1<0){
                if(v0<=v1) continue;
                int x=v1*v1-v0*v0;
                int y=2*a1;
                x=abs(x);
                y=abs(y);
                int p;
                if(x%y==0) p=x/y-1;
                else p=x/y;
                add(d,min(d+p,l));
            }else if(a1>0){
                if(v0>v1) add(d,l);
                else{
                    int x=v1*v1-v0*v0;
                    int y=2*a1;
                    int p=x/y+1;
                    if(d+p<=l) add(d+p,l);
                }
            }
        }
        for(int i = 1;i <= m;i++) scanf("%lld",&p[i]);
        int cnt=0,tot_k=0;
        for(int i = 1;i <= k;i++){
            //cout<<a[i].x<<" "<<a[i].y<<endl;
            int p1=lower_bound(p+1,p+m+1,a[i].x)-p;
            int p2=upper_bound(p+1,p+m+1,a[i].y)-p-1;
            if(p1==m+1||p2==m+1) continue;
            //cout<<a[i].x<<" "<<a[i].y<<endl;
            for(int j = p1;j <= p2;j++) c[j]++;
            //cout<<p[p1]<<" "<<p[p2]<<endl;
            if(p[p1]<=a[i].y||p[p2]>=a[i].x) cnt++;
            a[++tot_k]={p1,p2,false};
        }
        cout<<cnt<<" ";
        for(int i = 1;i <= m;i++) s[i]={i,c[i]};
        sort(s+1,s+m+1,cmp);
        //reverse(s+1.s+m+1,cmp);
        int sum=0,nt=0;
        int x,dis;

        while(sum<cnt){
            nt++;
            x=s[1].idx,dis=s[1].num;
            //cout<<x<<" "<<dis<<endl;
            c[x]=0;
            if(f[x]) continue;
            f[x]=true;
            sum+=dis;
            for(int j = 1;j <= tot_k;j++){
                if(a[j].r) continue;
                if(x>=a[j].x&&x<=a[j].y){
                        a[j].r=true;
                    for(int l = a[j].x;l <= a[j].y;l++){
                        if(l!=x){
                            c[l]--;
                        }
                    }
                }
            }

            for(int i = 1;i <= m;i++) s[i]={i,c[i]};
            sort(s+1,s+m+1,cmp);
            //x=s[1].idx,dis=s[1].num;
        }
        cout<<m-nt<<endl;
    }
    return 0;
}
