#include<iostream>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int m;
    cin>>m;
     int r[105],c[200005];
    int n,k,q;
    for(int mmm=1;mmm<=m;mmm++)
    {

        cin>>n>>k>>q;
        int l[n+2];
        int s[n+2][20005];

        for(int i=0;i<n;i++)
        {
            cin>>l[i];
            for(int j=0;j<l[i];j++)
            {
                cin>>s[i][j];
            }
        }


        for(int i=0;i<=q;i++)
        {
            cin>>r[i]>>c[i];
        }
    }

    for(int i=0;i<m*q;i++)
    {
        cout<<c[i]%2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
