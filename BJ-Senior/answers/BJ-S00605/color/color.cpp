#include<bits/stdc++.h>
using namespace std;
int n,T,a[214514];
bool t[214514];
long long ans;
int main(){
    freopen("color2.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(t[a[i]]) ans+=a[i];
            else t[a[i]]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
