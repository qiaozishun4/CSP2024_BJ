#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int t,n,m,l,V,d[2000005],v[2000005],a[2000005],p[2000005],rig[2000005],lef[2000005],cnt,ans1,ans2;
struct node{int l,r;}lin[2000005];
bool operator<(node x,node y){
    return x.r==y.r?x.l<y.l:x.r<y.r;
}
int main(){
    p[0]=-1;
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans1=ans2=0;
        cnt=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        //lef[0]=-1,rig[l]=l+1;
        for(int i=0;i<=l;i++)lef[i]=-1,rig[i]=l+1;
        for(int i=1;i<=m;i++){
            cin>>p[i];
            rig[p[i]]=lef[p[i]]=p[i];
        }
        for(int i=1;i<=l;i++)
            lef[i]=max(lef[i-1],lef[i]);
        for(int i=l-1;i>=0;i--)
            rig[i]=min(rig[i+1],rig[i]);
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V&&rig[d[i]]<=l){
                    ans1++;
                    lin[++cnt]={d[i],l};
                }
            }
            if(a[i]>0){
                if(v[i]<=V){
                    int s=(V*V-v[i]*v[i])/2/a[i];
                    int pp=d[i]+s+1;
                    if(pp<=l&&rig[pp]<=l){
                        ans1++;
                        lin[++cnt]={pp,l};
                    }
                }
                else{
                    if(rig[d[i]]<=l){
                        ans1++;
                        lin[++cnt]={d[i],l};
                    }
                }
            }
            if(a[i]<0){
                if(v[i]>V){
                    int s=(V*V-v[i]*v[i]+1)/2/a[i];
                    int pp=d[i]+s;
                    pp=min(pp,l);
                    if(rig[d[i]]<=pp){
                        ans1++;
                        lin[++cnt]={d[i],pp};
                    }
                }
            }
        }
        cout<<ans1<<" ";
        sort(lin+1,lin+cnt+1);
        int lst=0;
        for(int i=1;i<=cnt;i++){
            //cout<<lin[i].l<<" "<<lin[i].r<<"\n";
            if(lin[i].l<=p[lst]&&p[lst]<=lin[i].r)continue;
            while(!(lin[i].l<=p[lst]&&p[lst]<=lin[i].r))lst++;
            while(lst+1<=m&&(lin[i].l<=p[lst+1]&&p[lst+1]<=lin[i].r))lst++;
            ans2++;
            //cout<<lst<<"!\n";
        }
        cout<<m-ans2<<"\n";
    }
    return 0;
}
