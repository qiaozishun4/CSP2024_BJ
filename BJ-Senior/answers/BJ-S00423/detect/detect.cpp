#include<iostream>
#include<algorithm>
using namespace std;
int t,n,m,l,v,si,ssum,sum[1000005],uu[1000005];
int y2[1000005];
struct sss{
    int d,v,a;
}s[1000005];
struct sss2{
    int l,r;
}s2[1000005];
bool cmp(sss2 x,sss2 y){
    if(x.r==y.r){
        return x.l<y.l;
    }
    return x.r<y.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=0;i<=l;i++){
            sum[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>s[i].d>>s[i].v>>s[i].a;
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            sum[x]++;
            y2[i]=x;
        }
        for(int i=1;i<=l;i++){
            sum[i]=sum[i-1]+sum[i];
        }
        si=0;
        ssum=0;
        for(int i=1;i<=n;i++){
            if(s[i].a>0){
                if(s[i].v>v){
                    if(sum[l]-sum[s[i].d-1]>0){
                        s2[++si].l=s[i].d;
                        s2[si].r=l;
                        ssum++;
                    }
                }else{
                    int x=(v*v-s[i].v*s[i].v);
                    int u=2*s[i].a;
                    int r=x/u+1;
                    if(r+s[i].d<=l&&sum[l]-sum[r+s[i].d-1]>0){
                        s2[++si].l=r+s[i].d;
                        s2[si].r=l;
                        ssum++;
                    }
                }
            }else if(s[i].a<0){
                if(s[i].v>v){
                    int x=(s[i].v*s[i].v-v*v);
                    int u=-2*s[i].a;
                    int r=x/u;
                    if(x%u==0){
                        r--;
                    }
                    if(r+s[i].d>l){
                        r=l-s[i].d;
                    }
                    if(sum[r+s[i].d]-sum[s[i].d-1]>0){
                        s2[++si].l=s[i].d;
                        s2[si].r=r+s[i].d;
                        ssum++;
                    }
                }
            }else{
                if(s[i].v>v){
                    if(sum[l]-sum[s[i].d-1]>0){
                        s2[++si].l=s[i].d;
                        s2[si].r=l;
                        ssum++;
                    }
                }
            }
        }
        cout<<ssum<<" ";
        sort(s2+1,s2+1+si,cmp);
        int ss=1,ans=0,e=1,ss2=0;
        while(ss<=si){
            while(y2[ss2+1]<=s2[ss].r&&ss2+1<=m){
                ss2++;
            }
            ans++;
            e=ss;
            while(y2[ss2]>=s2[e].l&&e<=si){
                e++;
            }
            ss=e;
        }
        cout<<m-ans<<"\n";
    }
    return 0;
}
