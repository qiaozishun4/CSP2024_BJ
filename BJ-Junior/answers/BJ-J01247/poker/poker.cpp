#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,top=0;
    string p[100],up[100];
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool find=false;
        for(int j=1;j<=top;j++)
        {
            if(up[j]==p[i])
            {
                find=true;
                break;
            }
        }
        if(find==false) up[++top]=p[i];
    }
    cout << (52-top) << endl;
    return 0;
}
