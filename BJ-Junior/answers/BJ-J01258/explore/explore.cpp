#include <iostream>
using namespace std;
long long t,n,m,k,x,y,d;
char a;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
       cin>>n>>m>>k;
       cin>>x>>y>>d;
       for(int i=1;i<=n*m;i++){
            cin>>a;
       }
    }
    cout<<min(2*m+2*n-4,k);
    return 0;
}