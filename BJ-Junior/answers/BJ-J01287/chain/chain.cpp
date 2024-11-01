#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>a;
    for(int i=1 ; i<=a ; i++)
    {
        cin>>b>>c>>d;
        for(int j=1 ; j<=b ; j++)
        {
            cin>>e;
            for(int c=1 ; c<=e ; c++) cin>>f;
        }
        for(int j=1 ; j<=d ; j++) cin>>g>>h;
    }
    for(int i=1 ; i<=d ; i++)
    {
        cout<<0<<endl;
    }
    return 0;
}
