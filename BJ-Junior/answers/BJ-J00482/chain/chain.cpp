#include <iostream>
using namespace std;
int t,n,k,q,ll,r,l[100005],now;
char s[200005],c;
int ans(int lun,int ren,char tgt);
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int qw=0;qw<t;++qw){
        cin>>n>>k>>q;
        now=0;
        for(int i=0;i<n;++i){
            cin>>ll;
            l[i]=now;
            for(int j=0;j<ll;++j)cin>>s[now++];
        }
        for(int i=0;i<q;++i){
            cin>>r>>c;
            cout<<ans(r,-1,c)<<endl;
        }
    }
    return 0;
}
int ans(int lun,int ren,char tgt){
    int ret=0;
    int nn=0;//ren
    for(int i=0;i<now;++i){//i dijige
        if(i>=l[nn+1])++nn;
        if(s[i]==tgt&&nn!=ren){//xiayigeren de end
            for(int j=1;j<k;++j){
                if(i-j<l[nn])break;
                if(lun<=1){
                    if(s[i-j]=='1')return 1;
                    continue;
                }
                ret=ans(lun-1,nn,s[i-j]);
                if(ret==1)return 1;
            }
        }
    }
    return 0;
}
