#include<bits/stdc++.h>
using namespace std;
int main(){//RP++
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int i,n,t,c,q,d,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>c>>q;
        for(i=0;i<n;i++)
        {
            cin>>c;
            while(c--)
                cin>>b;
        }
        while(q--)
        {
            cin>>c>>d;
            cout<<(c+d)%2<<endl;
        }
    }
    return 0;
}//原稿没了(本来就不会)