#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,x,t,a[N],flag[N],ans;
int check(){
    int ans=0;
    for(int i=1;i<=n;i++){
        int bflag=0;
        for(int j=i-1;j>0 && !bflag;j--){
            if(flag[i]==flag[j]){
                if(a[i]==a[j])ans+=a[i];
                bflag=1;
            }
        }
    }
    return ans;
}
void f(int m,int c){
    if(m==n){
        ans=max(ans,check());
        return;
    }
    flag[m]=c;
    f(m+1,0);
    f(m+1,1);
}
int main(){

    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        f(1,0);
        f(1,1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
