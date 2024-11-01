#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int T,n,a[N],tmp0[N],tmp1[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int cnt0=0,cnt1=0,tmp=i,curans=0;
            for(int j=1;j<=n;j++){
                if(tmp&1==1)tmp0[++cnt0]=a[j];
                else tmp1[++cnt1]=a[j];
                tmp>>=1;
            }
            for(int j=1;j<cnt0;j++)
                if(tmp0[j]==tmp0[j+1])
                    curans+=tmp0[j];
            for(int j=1;j<cnt1;j++)
                if(tmp1[j]==tmp1[j+1])
                    curans+=tmp1[j];
            ans=max(ans,curans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//Workingmen of all countries, unite!