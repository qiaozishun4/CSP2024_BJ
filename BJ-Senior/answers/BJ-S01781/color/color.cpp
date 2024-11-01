#include<bits/stdc++.h>
using namespace std;
int T,n;
int s[200005];
int t[200005];
long long ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int _=1;_<=T;_++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            t[i]=s[i];
        }
        sort(t+1,t+1+n);
        for(int i=1;i<n;i++){
            if(t[i]==t[i+1]){
                ans+=t[i];
            }
        }
        cout<<ans<<endl;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        ans=0;
    }
    return 0;
}