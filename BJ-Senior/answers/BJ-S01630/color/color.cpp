#include<bits/stdc++.h>
using namespace std;
int n;
int c[200005];
int pre[200005];
int bin[1000006];
long long f1[200005];
long long f2[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        memset(bin,0,sizeof(bin));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            pre[i]=bin[c[i]];
            bin[c[i]]=i;
//            cout<<pre[i]<<" ";
        }
//        cout<<endl;
        for(int i=2;i<=n;i++){
            if(pre[i]==i-1){
                ans+=c[i];
                f1[i]=f1[i-1];
                f2[i]=f2[i-1];
                continue;
            }
            f1[i]=max(f1[i],f1[i-1]);
            if(pre[i]!=0){
                f2[i]=c[i]+max(f1[pre[i]],f2[pre[i]+1]);
            }
            f1[i]=max(f1[i],f2[i]);
        }
        cout<<ans+f1[n]<<endl;
    }
    return 0;
}
