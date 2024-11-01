#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200050],b[200050],lst[100050];
int lowbit(int p){
    return p&-p;
}
void add(int p,ll k){
    for(int i=p;i<=n;i+=lowbit(i))b[i]+=k;
}
ll pre(int p){
    ll sum=0;
    for(int i=p;i>0;i-=lowbit(i)){
        sum+=b[i];
    }
    return sum;
}
ll q(int l,int r){
    if(l>r)return 0;
    return pre(r)-pre(l-1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(b,0,sizeof b);
        memset(lst,0,sizeof lst);
        ll ans=0;
        for(int i=1;i<=n;i++){
            int past=q(i-1,i-1);
            if(lst[a[i]]==0){
                if(past==1)add(i,1);
            }else{
                int j=lst[a[i]],tj=q(j,j);
                int num=q(j+1,i-1);
                if(num!=0 && num!=i-j-1){
                    if(past==0)add(i,1);
                }else if(num==0 && tj==1 || num==i-j-1 && tj==0){//已匹配
                    if(tj==1)add(i,1);
                    ans+=a[i];
                }else{
                    if(tj==1)add(j,-1);
                    if(tj==0)add(j,1),add(i,1);
                    ans+=a[i];
                }
            }
            lst[a[i]]=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}