#include<bits/stdc++.h>
/*why we need to know how fast the car is?
we only need to know where the car is fast
a car is fast in such[l,r]
then,if a car fast with a detect,he will be detected
if a car fast in the min r
we can close all detect belong to his,except the last one
this can detect most
then we can continue, and we only need to judge other cars's l
priority queue is a great tool for us
then it is quite easy
*/
using namespace std;

#define int long long
const int N=1e5+7;
int T,n,m,L,V,ans1,ans2;
int det[10*N];
struct node{int l,r;}car[N],car2[N];
bool operator <(node x,node y){return x.r<y.r;}
bool operator >(node x,node y){return x.r>y.r;}
priority_queue<node,vector<node>,greater<node> > q;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    for(int _=1;_<=T;_++){
        memset(det,0,sizeof(det));
        ans1=0,ans2=0;
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            node c;c.l=-1;
            int d,v,a,s,s2;
            scanf("%lld%lld%lld",&d,&v,&a);
            if(a==0){
                if(v>V){
                    c.l=d;
                    c.r=L;
                }
            }
            if(a>0){
                if(v>V){
                    c.l=d;
                    c.r=L;
                }
                else{
                    s=(V*V-v*v)/(2*a);
                    s2=(V*V-v*v)%(2*a);
                    s++;
                    c.l=d+s;c.r=L;
                }
            }
            if(a<0){
                if(v>V){
                    s=(V*V-v*v)/(2*a);
                    s2=(V*V-v*v)%(2*a);
                    if(s2==0) s--;
                    //cout<<s<<endl;
                    c.l=d;c.r=min(d+s,L);
                }
            }
            car[i]=c;
        }
        for(int i=1;i<=m;i++){
            int p;
            scanf("%lld",&p);
            det[p]=1;
        }
        for(int i=0;i<=L;i++){

            if(det[i]){
                det[i]=det[i-1]+1;
            }
            else{
                det[i]=det[i-1];
            }
            //cout<<det[i]<<endl;
        }
        for(int i=1;i<=n;i++){

            node c=car[i];
            //cout<<c.l<<" "<<c.r<<endl;
            if(c.l==-1 or c.l>c.r){
                continue;
            }
            if(c.l)c.l=det[c.l-1]+1;
            else c.l=1;
            c.r=det[c.r];
            if(c.l<=c.r) {q.push(c);ans1++;}
        }
        int kl=-1;
        while(!q.empty()){
            node c=q.top();
            q.pop();
            if(c.l<=kl) continue;
            ans2++;
            kl=c.r;
        }
        cout<<ans1<<" "<<m-ans2<<endl;

    }
}
