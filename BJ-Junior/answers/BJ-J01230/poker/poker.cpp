#include <iostream>
#include <cstring>
using namespace std;
int num;
int cnt;
bool d[500];
bool c[500];
bool h[500];
bool s[500];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        string a;
        cin>>a;
        int target=a[1];
        if(a[0]=='D'&&d[target]==false)
        {
            cnt++;
            d[target]=true;
        }
        if(a[0]=='C'&&c[target]==false)
        {
            cnt++;
            c[target]=true;
        }
        if(a[0]=='H'&&h[target]==false)
        {
            cnt++;
            h[target]=true;
        }
        if(a[0]=='S'&&s[target]==false)
        {
            cnt++;
            s[target]=true;
        }
    }
    int ans=52-cnt;
    cout<<ans<<endl;
    return 0;
}