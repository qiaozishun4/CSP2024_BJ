#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int aa[N],c[N],n,m,po2[35],K,X[4],a[N],vip[N];
ll res[N],ans;
string s[25];
int t[25][N];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    po2[0]=1;
    for(int i=1;i<=25;++i){
        po2[i]=po2[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=25;++i){
        if(po2[i]>=n){
            K=i;
            break;
        }
    }
    for(int i=1;i<=n;++i){
        cin>>aa[i];
    }
    for(int i=1;i<=m;++i){
        cin>>c[i];
        for(int j=0;j<=K;++j){
            if(c[i]==po2[j]){
                vip[i]=1;
                break;
            }
        }
    }
    for(int i=1;i<=K;++i){
        cin>>s[i];
    }
    int T;
    cin>>T;
    while(T--){
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for(int i=1;i<=n;++i){
            a[i]=aa[i]^X[i%4];
        }
        for(int i=1;i<=m;++i){
            if(vip[i]){
                for(int j=1;j<=c[i];++j){
                    t[1][j]=j;
                }
                int cnt=c[i],cmn=1;
                for(int j=1;j<=K;++j){
                    if(cnt==1) break;
                    for(int l=0;l<s[j].size();++l){
                        if(s[j][l]=='1'){
                            if(a[t[j][2*(l+1)]]>=j){
                                t[j+1][l+1]=t[j][2*(l+1)];
                            }else{
                                t[j+1][l+1]=t[j][2*(l+1)-1];
                            }
                        }else{
                            if(a[t[j][2*(l+1)-1]]>=j){
                                t[j+1][l+1]=t[j][2*(l+1)-1];
                            }else{
                                t[j+1][l+1]=t[j][2*(l+1)];
                            }
                        }
                        //cout<<t[j+1][l+1];
                    }
                    //cout<<endl;
                    cnt/=2;
                    ++cmn;
                }
                res[i]=t[cmn][1];
                continue;
            }
        }
        ans=0;
        for(int i=1;i<=m;++i){
            //cout<<res[i]<<endl;
            ans^=(1ll*i*res[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
