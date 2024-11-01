#include <iostream>
#include <string>
using namespace std;
string mp[]={"10","1","200","20","2","6","8"};
int m[]={0,-1,1,7,4,2,6,8,-1,-1,22};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n<=10)
        {
            cout<<m[n]<<endl;
            continue;
        }
        cout<<mp[(n-1)%7];
        int nn;
        if (n%7==0)
        {
            nn=(n-1)/7+1-(int)mp[(n-1)%7].size();
        }
        else
        {
            nn=n/7+1-(int)mp[(n-1)%7].size();
        }
        for (int i=1;i<=nn;i++)
        {
            cout<<'8';
        }
        cout<<endl;
    }
    return 0;
}
