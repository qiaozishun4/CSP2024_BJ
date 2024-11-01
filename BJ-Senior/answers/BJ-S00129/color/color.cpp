#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,a[N],b[N],ans=0;
int t;//...
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[1]=2;
            b[2]=1;
            if(a[1]==a[2])b[2]=1,b[3]=2;
            for(int j=i;j>0;j--){
                if(a[j]==a[i]&&b[j]=0)b[i]=b[j];
                for(int k=i-1;k>j;k--){
                    if(b[j]==b[k]&&b[j]==1)b[j]=b[i]=2;
                    else b[j]=b[i]=1;
                }
                for(int k=i-1;k>j;k--)if(b[j]==b[k])b[j]=0,b[i]=0;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(b[i]==b[j]&&a[i]==a[j])ans+=a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}