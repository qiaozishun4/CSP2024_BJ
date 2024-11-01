#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
bool c[200005];
int main(){
    a[0]=-1;
    int T;
    cin>>T;
    while(T--){
        int m[1000005],ma[1000005];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        c[n]=0;
        m[a[n]]=n;
        for(int i=n-1;i>=1;i--){
            if(m[a[i]]==0){
                c[i]=c[i+1]+1;
                m[a[i]]=i;
            }else{
                c[i]=c[m[a[i]]];
                m[a[i]]=i;
            }
        }
        long long ans;
        for(int i=1;i<=n;i++){
            if(a[ma[c[i]]]==a[i]) ans+=a[i];
            ma[c[i]]=i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
