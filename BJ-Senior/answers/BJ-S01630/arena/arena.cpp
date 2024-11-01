#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int oa[100005];
int c[100005];
int a[100005];
int ans[300005];
int res[100005];
int R[300005];
int ans2=0;
int psw=0;
int mk=0;
bool d[300005];
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(d,0,sizeof(d));
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>oa[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    while((1<<mk)<n)mk++;
    int mxsn=(1<<mk)-1;
    for(int i=mk-1;i>=0;i--){
        for(int j=(1<<i);j<=(1<<(i+1))-1;j++){
            char x;
            cin>>x;
            d[j]=bool(x=='1');
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)a[i]=oa[i]^x[i%4];
//        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
   //     cout<<endl;
        for(int i=2*mxsn+2;i>=1;i--){
            if(i>mxsn)ans[i]=i-mxsn,R[i]=0;
            else ans[i]=ans[i*2]+ans[i*2+1],R[i]=1+R[i*2];
        }
        for(int i=1;i<=n;i++){
            int kk=0;
            while((1<<kk)<i)kk++;
            int endx=((mxsn+i)>>kk);
            int x=mxsn+i;
            ans2=0;
            psw=i;
            while(x!=endx){
   //             cout<<i<<" "<<x<<" "<<ans2<<" "<<psw<<endl;
                if(x&1){
                    if(d[x>>1]==0){
                        if(a[ans[x-1]]>=R[x>>1]){
                            ans[x>>1]=ans[x-1];
                            psw=ans[x-1];
                            ans2=0;
    //        cout<<1<<endl;
                        }else{
                            ans[x>>1]=ans[x];
    //        cout<<2<<endl;
                        }
                    }else{
                        if(psw!=0&&a[psw]>=R[x>>1]){
                            ans[x>>1]=ans[x];
                            if(ans2!=0)ans2+=ans[x-1];
                            //GG
     //       cout<<3<<endl;
                        }else{
                            ans[x>>1]=ans[x-1];
                            psw=ans[x-1];
    //        cout<<4<<endl;
                        }
                    }
                }else{
                    if(d[x>>1]==0){
                        if(psw!=0&&a[psw]>=R[x>>1]){
                            ans[x>>1]=ans[x]+ans[x+1];
                            if(ans2!=0)ans2+=ans[x+1];
     //       cout<<5<<endl;
                        }else{
                            ans2+=ans[x+1];
                            ans[x>>1]=ans[x]+ans[x+1];
                            psw=0;
     //       cout<<6<<endl;
     //       cout<<a[psw]<<" "<<R[x>>1]<<endl;
                        }
                    }else{
                        ans2+=ans[x+1];
                        ans[x>>1]=ans[x]+ans[x+1];
     //       cout<<7<<endl;
                    }
                }
     //           cout<<i<<" "<<x<<" "<<ans2<<" "<<psw<<endl;
                x>>=1;
            }
            res[i]=psw+ans2;
        }
   //     for(int i=1;i<=n;i++)cout<<res[i]<<" ";
   //     cout<<endl;
        int out=0;
        for(int i=1;i<=m;i++){
            out^=(i*res[c[i]]);
        }
        cout<<out<<endl;
    }
    return 0;
}
