#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10,Q = 15;
int T,n,a[N],c[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0,ans=0;
        for(int i=1;i<(1<<n);i++){
            cnt=0;
            for(int j=1;j<=n;j++){
                int bz=0;
                for(int k=1;k<j;k++){
                    int z=((1<<(k-1))&i);
                    int p=((1<<(j-1))&i);
                    if(z==0&&p==0){
                        bz=k;
                    }
                    if(z!=0&&p!=0){
                        bz=k;
                    }
                }
                if(bz!=0){
                    if(a[j]==a[bz]){
                        cnt+=a[j];
                    }
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}