#include<bits/stdc++.h>
using namespace std;
long long n,a[20],ans,t;
bool b[20];
void v(int x){
    if(x==n){
        long long num=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(b[i]==b[j]){
                    if(a[i]==a[j]) num+=a[j];
                    else break;
                }
            }
        }ans=max(ans,num);
        return;
    }
    b[x]=0;
    v(x+1);
    b[x]=1;
    v(x+1);
    return;
}
int main(){
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        v(1);
        cout<<ans<<endl;
    }
    return 0;
}
