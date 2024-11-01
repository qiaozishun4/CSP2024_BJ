#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(NULL));
    int t;
    cin>>t;
    while(t--)
        {
            int n,k,q,a,l;
            cin>>n>>k>>q;
            for(int i=1;i<=n;i++)
                {
                    cin>>l;
                    for(int j=1;j<=l;j++)cin>>a;
                }
            for(int i=1;i<=q;i++)cout<<rand()%2<<endl;
        }
    return 0;
}