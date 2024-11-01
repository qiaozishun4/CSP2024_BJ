#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],b[N];
int t[N];
int n,k;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>k;
    while(k--){
        long long ans=0;
        memset(t,0,sizeof(t));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            t[a[i]]++;
        }int top=1;
        for(int i=1;i<=n;i++){
            if(t[a[i]]>=2){
                b[top]=a[i];
                top++;
            }
        }for(int i=2;i<top;i++){
            if(b[i]==b[i-2])ans+=b[i];
            if(b[i]==b[i-1])ans+=b[i];
            if(b[i]==b[i-1]&&b[i+1]==b[i-2])ans+=b[i+1];
        }cout<<ans<<endl;
    }fclose(stdin);
    fclose(stdout);

return 0;
}
