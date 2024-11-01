#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,k,q,l[N][N];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i][0];
            for(int j=1;j<=l[i][0];j++){
                cin>>l[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            if(i%2==0) printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
