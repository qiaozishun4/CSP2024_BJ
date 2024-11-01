#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,x,cnt=0;
char o;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a>>b>>c;
        cin>>x>>x>>x;
        for(int i=1 ; i<=a ; i++)
        {
            for(int j=1 ; j<=b ; j++)
            {
                cin>>o;
                if(o=='x') cnt++;
            }
            cout<<c-cnt<<endl;
        }
    }
    return 0;
}
