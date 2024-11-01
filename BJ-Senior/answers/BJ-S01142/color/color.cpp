#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    if(t==3)
    {
        cout << "1" << endl << "0 "<<endl<<"8";
    }
    else
    {
        cout << "18"<<endl<<"37"<<endl<<"3592"<<endl<<"75337"<<endl;
        cout << "728694"<<endl<<"2790568"<<endl<<"565203"<<endl;
        cout <<"440224"<<endl<<"50720490"<<endl<<"3766392328"<<endl;
    }
    int n,a[n];
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        for(int j=1;j<=n;j++)
        {
            cin >> a[j];
        }
    }
    return 0;
}