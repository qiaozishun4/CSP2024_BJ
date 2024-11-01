#include <bits/stdc++.h>
#define maxn 200055
using namespace std;
int t,n,a[maxn],fa[maxn],ans=0;
inline int findx(int x){
    return fa[x]==x?x:findx(fa[x]);
}
inline void mmerge(int x,int y){
    int xx=findx(x);
    int yy=findx(y);
    fa[yy]=xx;
    return;
}
inline int findx2(int x){
    int ttttttt=x;
    for(int i=ttttttt-1;i>=1;i--){
        if(a[i]==a[x]){
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int ww=1;ww<=t;ww++){
        cin>>n;
        ans=0;
        memset(a,0,sizeof(a));
        memset(fa,0,sizeof(fa));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
        for(int i=2;i<=n;i++){
            int ii=findx2(i);
            if(ii){
                mmerge(ii,i);
                ans+=a[i];
            }else{
                mmerge(0,i);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

