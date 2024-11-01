#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("/home/cspj/test12/test2/sticks.in","r",stdin);
    freopen("/home/cspj/test12/test2/sticks.out","w",stdout);
    int d;
    cin>>d;
    for (int i=0;i<d;i++)
    {
        int s;
        cin>>s;
        if (s==1)
        {
            cout<<-1<<endl;
        }
        else if (s%7==0)
        {
            for (int i=0;i<s/7;i++)
            {
                cout<<8;
            }
            cout<<endl;
        }
        else if (s%6==0)
        {
            cout<<6;
            for (int i=1;i<s/6;i++)
            {
                cout<<0;
            }
            cout<<endl;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
