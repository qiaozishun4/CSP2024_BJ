#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

const int N=100005;
int n,r[N],ans;

int main()
{
    fio("duel");
    cin>>n,ans=n;
    for(int i=1;i<=n;i++) cin>>r[i];
    sort(r+1,r+1+n);
    for(int i=2,j=1;i<=n;i++) if(r[i]>r[j]) ans--,j++;
    cout<<ans;
    return 0;
}