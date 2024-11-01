#include<iostream>
#include<algorithm>
using namespace std;
long long a[100010];
long long n,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]&&a[i-1]!=-1) a[i-1]=-1;
        else
        {
            for(int j=i-2;j>=1;j--)
            {
                if(a[i]>a[j]&&a[j]!=-1)
                {
                    a[j]=-1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=-1) ans++;
    cout<<ans<<endl;
    return 0;
}

