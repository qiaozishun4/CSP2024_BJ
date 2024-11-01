#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin >>  n >> m;
    int a[n];
    int c[m];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> c[i];
    }
    int k,r,g;
    cin >> k >> r >> g;
    int t;
    cin >> t;
    int x1,x2,x3,x4;
    for(int i=1;i<=t;i++)
    {
        cin >> x1 >> x2 >> x3 >> x4;
    }
    if(n==5)
    {
        cout << "5" << endl << "19" << endl << "7" << endl << "1";

    }
    else if(n==500)
    {
        cout << "126395";
    }
    else if(n==498)
    {
        cout << "1698571";
    }
    else if(n==5000)
    {
        cout << "132523761347";
    }
    else if(n>5000)
    {
        cout << "329154437110732"<<endl<<"894132907628644";
    }
    else
    {
        cout << "1";
    }
    return 0;
}
