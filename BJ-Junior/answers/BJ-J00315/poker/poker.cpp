#include <bits/stdc++.h>
using namespace std;

string pokers[100];
string pv[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int pvc=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pokers[i];
        bool alrh=false;
        for(int j=0;j<pvc;j++)
        {
            if(pv[j]==pokers[i])
            {
                alrh=true;
                break;
            }
        }
        if(!alrh)
        {
            pv[pvc]=pokers[i];
            pvc++;
        }
    }
    cout<<52-pvc;
    return 0;
}
