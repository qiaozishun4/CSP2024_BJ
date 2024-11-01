#include<iostream>
using namespace std;
long long a[100010];
long long c[100010];
long long T,n,ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) c[i]=0;
        for(int i=2;i<=n;i++)
            for(int j=i-1;j>=1;j--)
                if(a[i]==a[j]) c[i]=a[i];
        for(int i=1;i<=n;i++) ans+=c[i];
        cout<<ans<<endl;
    }
    return 0;
}

