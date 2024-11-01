#include <iostream>
#include <cstring>
using namespace std;
int a[20];
bool c[20];
int k[110];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        memset(a,0x00,sizeof(a));
        memset(c,0x00,sizeof(c));
        memset(k,0x00,sizeof(k));
        int n;
        cin>>n;
        if(n<=15){
            int ans=0;
            for(int i=1;i<=n;i++)   cin>>a[i];
            for(int i=0;i<(1<<n);i++){
                //target
                for(int j=1;j<=n;j++){
                    c[j]=i&(1<<(j-1));
                }
                int lastr=0,lastl=0;
                for(int j=1;j<=n;j++){
                    if(c[j])    k[j]=lastl,lastl=j;
                    else    k[j]=lastr,lastr=j;
                }
                int sum=0;
                for(int j=1;j<20;j++)
                {
                    if(a[j]==a[k[j]])   sum+=a[j];
                }
                ans=max(ans,sum);
            }
            cout<<ans;
        }
        else{
            for(int i=0;i<n;i++){
                int tmp;
                cin>>tmp;
            }
        }
    }
    return 0;
}
