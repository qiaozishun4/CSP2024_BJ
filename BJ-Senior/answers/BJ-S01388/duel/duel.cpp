#include <iostream>
#include <algorithm>
using std::ios;
using std::cin;
using std::cout;
using std::sort;
using std::unique;
using std::endl;

const int N=1e5+5;
int n,ans=0,r[N],m,a[N],b[N];

signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        a[i]=r[i];
    }
    sort(r+1,r+1+n);
    int m=unique(r+1,r+1+n)-r-1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
        if(r[i]==a[j]){
            b[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        ans+=b[i];
        if(i==m){
            break;
        }
        if(ans<=b[i+1]){
            ans=0;
        }else{
            ans=ans-b[i+1];
        }
    }

    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}