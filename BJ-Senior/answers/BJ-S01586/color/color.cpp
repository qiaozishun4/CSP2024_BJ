#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
namespace nless100{
    int f[105][105],a[105];
    void pts(int n){
        _for(i,1,n) cin>>a[i];
        int ans=0;
        _for(i,1,n){
            int sum=0;
            _for(len,1,i){
                int l=i-len+1,r=i;
                //cout<<i<<','<<len<<','<<k<<','<<l<<':';
                if(l!=i&&(a[l]==a[l+1])) sum+=a[l];
                _for(L,1,l-1)
                    //cout<<l-1-L+1<<' ',
                    f[i][len]=max(f[l-1][L]+sum+(l-1-L>0&&a[l-1-L]==a[l])*a[l],
                                     f[i][len]);
                ans=max(ans,f[i][len]);
                //cout<<sum<<' ';
                //cout<<'\n';
            }
            //cout<<ans<<' ';
            //cout<<'\n';
        }
        cout<<ans<<'\n';
        //cout<<'\n';
        _for(i,0,n){
            _for(j,0,n)
                f[i][j]=0;
        }
    }
}

namespace nless2000{
    int f[2005][2005],a[2005];
    int g[2005];
    int h[2005][2005];
    void pts(int n){
        _for(i,1,n) cin>>a[i];
        int ans=0;
        _for(i,0,n){
            _for(j,0,n)
                f[i][j]=g[i]=0,h[i][j]=-1;
        }
        _for(i,1,n){
            int sum=0;
            _for(j,1,i){
                int l=i-j+1,r=i;
                //cout<<i<<','<<j<<','<<k<<','<<l<<':';
                if(l!=i&&(a[l]==a[l+1])) sum+=a[l];
                f[i][j]=max({f[i][j],(h[l-1][a[l]]!=-1?sum+h[l-1][a[l]]+a[l]:0),sum+g[l-1]});

                h[i][a[l-1]]=max(h[i][a[l-1]],f[i][j]);
                g[i]=max(g[i],f[i][j]);
                ans=max(ans,g[i]);
                //cout<<sum<<' ';
                //cout<<'\n';
            }
            //cout<<ans<<' ';
            //cout<<'\n';
        }
        cout<<ans<<'\n';
        //cout<<'\n';
    }
}
int T,n,f[200005],a[200005];
int g[200005];bool vis[25];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    int B=15;
    while(T--){
        cin>>n;
        if(n<=B){
            _for(i,1,n){
                cin>>a[i];
            }
            int ans=0;
            _rep(i,0,(1<<15)){
                _for(j,0,14){
                    vis[j+1]=(((1<<j)&i)>0);
                }
                int sum=0,lsb=0,lsr=0;
                _for(j,1,n){
                    if(vis[j]==0){
                        sum+=(a[lsb]==a[j])*a[j];
                        lsb=j;
                    }else{
                        sum+=(a[lsr]==a[j])*a[j];
                        lsr=j;
                    }
                }
                ans=max(ans,sum);
            }
            cout<<ans<<'\n';
            continue;
        }else if(n<=100){
            nless100::pts(n);
        }else if(n<=2000){
            nless2000::pts(n);
        }else{
            _for(i,1,n){
                cin>>a[i];
            }
        }
    }
    return 0;
}
