#include <iostream>
#include <cstring>
using namespace std;
int a[5005],c[5005],l;
long long ans;
void bao(int d){
    if(d>l){
        int r=0,b=0;//r->0,b->1;
        long long anss=0;
        for(int i=l;i>0;i--){
            if(r==0&& c[i]==0){
                r=a[i];
                continue;
            }

            if(b==0&& c[i]==1){
                b=a[i];
                continue;
            }
            if(c[i]==0){
                if(a[i]==r)anss+=r;
                else r=a[i];
            }
            if(c[i]==1){
                if(a[i]==b)anss+=b;
                else b=a[i];
            }
        }
        ans=max(ans,anss);
        return;
    }
    for(int i=0;i<=1;i++){
        c[d]=i;
        bao(d+1);
    }
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int q;
    cin>>q;
    for(int qq=0;qq<q;qq++){
        cin>>l;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        ans=0;
        for(int i=1;i<=l;i++){
            scanf("%d",&a[i]);
        }
        bao(1);
        cout<<ans<<endl;
    }
    return 0;
}
