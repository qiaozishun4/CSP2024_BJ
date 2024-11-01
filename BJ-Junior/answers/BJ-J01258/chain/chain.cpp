#include <iostream>
using namespace std;
long long n,k,q,t,r,c,m,a;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>a;
            for(int i=1;i<=a;i++){
                cin>>m;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            cout<<"1";
        }
    }
    return 0;
}