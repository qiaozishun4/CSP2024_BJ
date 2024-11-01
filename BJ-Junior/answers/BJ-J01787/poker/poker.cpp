#include <iostream>
#include <stdio.h>
using namespace std;
bool a[5][14];
char str[3];
int n,ans,l[128],r[128];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    l['D']=1;
    l['C']=2;
    l['H']=3;
    l['S']=4;
    r['A']=1;
    for(int i=2;i<=9;i++)
        r[i+'0']=i;
    r['T']=10;
    r['J']=11;
    r['Q']=12;
    r['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(!a[l[str[0]]][r[str[1]]])
        {
            ans++;
            a[l[str[0]]][r[str[1]]]=1;
        }
    }
    cout<<52-ans;
    return 0;
}
