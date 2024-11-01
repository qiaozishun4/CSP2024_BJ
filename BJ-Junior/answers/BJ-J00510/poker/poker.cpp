#include<bits/stdc++.h>
using namespace std;
string p;
int n,c=1,h;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string poker[52]={"no"};
    for(int i=0;i<n;i++)
    {
        cin>>p;
        for(int j=0;j<n;j++)
        {
            if(p==poker[j])
            {
                c=0;
            }
        }
        if(c==1)
        {
            poker[i]=p;
        }
        else
        {
            poker[i]="no";
            c=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(poker[i]!="no")
        {
            h++;
        }
    }
    cout<<52-h;
    return 0;
}