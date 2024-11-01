#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("/home/cspj/test12/test1/poker.in","r",stdin);
    freopen("/home/cspj/test12/test1/poker.out","w",stdout);
    int w;
    cin>>w;
    string a;
    string oll[100];
    int s=0;
    for (int i=0;i<w;i++)
    {
        cin>>a;
        int in=0;
        for (int j=0;j<s;j++)
        {
            if (oll[j]==a)
            {
                in=1;
                break;
            }
        }
        if (in==0)
        {
            s++;
            oll[s-1]=a;
        }

    }
    cout<<52-s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
