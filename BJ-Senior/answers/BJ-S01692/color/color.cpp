#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int n,t,x,tong[N],c,biao[N];

int main()
{
    freopen("color2.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long ans=0;
        c=0;
        memset(tong,0,sizeof(tong));
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(tong[x]==0) c++,biao[c]=x;
            tong[x]++;
        }
        for(int i=1;i<=c;i++){
            int p=ans;
            ans+=(tong[biao[i]]/2)*biao[i];
            //if(ans!=p) cout<<biao[i]<<" "<<(tong[biao[i]]/2)*biao[i]<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
