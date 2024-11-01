#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100005];
bool f[100005];
void sov(){
    int ans=0;
    for(int i=1;i<=(1<<n)-1;i++){
            memset(f,false,sizeof(f));
            int sum=0;
            for(int j=i,p=1;j;j>>=1,p++){
                if(j&1){
                    f[p]=true;
                }
            }
            int h1=0,h2=0;
            for(int i=1;i<=n;i++){

                if(f[i]==true){
                    if(a[h1]==a[i]){
                        sum+=a[i];
                    }
                    h1=i;
                }else{
                    if(a[h2]==a[i]){
                        sum+=a[i];
                    }
                    h2=i;
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=100){
            sov();
        }else{
            int sum=0;
            for(int i=1;i<=n;i++){
                sum=sum+(a[i]==a[i-1])*a[i];
            }
            cout<<sum<<endl;
        }
    }
}
