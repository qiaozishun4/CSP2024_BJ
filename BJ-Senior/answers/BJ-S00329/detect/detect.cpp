#include<bits/stdc++.h>
using namespace std;
struct node{
    int s;
    double v,add;
}a[100050];
int n,m,L,V;
int st[1000050][20],lg[1000050],mp[1000050],b[1000050];
void init(){
    for(int i=1;i<=n;i++)st[i][0]=mp[i],lg[i]=lg[i/2]+1;
    for(int j=1;j<=lg[n];j++){
        for(int i=1;i<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int q(int l,int r){
    int len=r-l+1;
    return max(st[l][lg[len/2]],st[r-len/2+1][lg[len/2]]);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].v>>a[i].add;
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        int ans1,ans2=2e9;
        for(int p=0;p<(1<<m);p++){
            memset(mp,0,sizeof mp);
            int cnt=0;
            for(int i=1;i<=m;i++){
                if(p&(1<<i)){
                    mp[b[i]]=1;
                    cnt++;
                }
            }
            init();
            int flag=1,sum=0;
            for(int i=1;i<=n;i++){
                double l,r;
                if(a[i].add==0){
                    l=a[i].s,r=L+1;
                }else{
                    l=(m*m-a[i].v*a[i].v)/2/a[i].add+a[i].s;
                    r=(-a[i].v*a[i].v)/2/a[i].add+a[i].s;
                }
                if(q(l,r)==0){
                    flag=0;
                }else if(p==(1<<m)-1)sum++;
            }
            if(flag)ans2=min(ans2,cnt);
            if(sum!=0)ans1=sum;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}