#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100005],t,x[5],a2[100005],ans[100005];
int s[25][300005];
struct sss{
    int c,id;
}c[100005];
bool cmp(sss x,sss y){
    return x.c<y.c;
}
int dfs(int l,int r,int d,int g){
    if(r==l+1){
        int u1=l,u2=r;
        if(s[d][g]==0){
            if(a2[u1]>=d) return u1;
            else return u2;
        }else{
            if(a2[u2]>=d) return u2;
            else return u1;
        }
    }
    int mid=(l+r)/2;
    int u1=dfs(l,mid,d+1,g*2);
    int u2=dfs(mid+1,r,d+1,g*2+1);
    if(s[d][g]==0){
        if(a2[u1]>=d) return u1;
        else return u2;
    }else{
        if(a2[u2]>=d) return u2;
        else return u1;
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    int v=n,anss=0;
    while(v>0){
        anss++;
        v/=2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i].c;
        c[i].id=i;
    }
    for(int i=anss;i>0;i--){
        for(int j=1;j<=(1<<(i-1));j++){
            char cc;
            cin>>cc;
            if(cc=='0'||cc=='1'){
                s[i][j]=cc-'0';
            }else{
                j--;
            }
        }
    }
    sort(c+1,c+1+m,cmp);
    cin>>t;
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++){
            a2[i]=a[i]^x[i%4];
        }
        for(int i=1;i<=m;i++){
            if(c[i].c==c[i-1].c){
                ans[c[i].id]=ans[c[i-1].id];
            }else{
                if(c[i].c==1){
                    ans[c[i].id]=1;
                }else{
                    ans[c[i].id]=dfs(1,c[i].c,1,1);
                }
            }
        }
        int sum=0;
        for(int i=1;i<=m;i++){
            sum^=(ans[i]*i);
        }
        cout<<sum<<"\n";
    }
    return 0;
}
