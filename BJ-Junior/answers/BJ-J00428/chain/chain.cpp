#include<bits/stdc++.h>

using namespace std;

int t;

void work()
{
    vector<int> s[100000];
    int n,k,q,l,g,r,c;
    cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        while(l--)
        {
            cin>>g;
            s[i].push_back(g);
        }
    }
    while(q--)
    {
        cin>>r>>c;
        if(r==1)
        {
            bool flag=false;
            for(int i=0;i<n&&flag==false;i++)
            {
                for(int j=0;j+1<s[i].size()&&flag==false;j++)
                {
                    if(s[i][j]==1&&s[i][j+1]==c)
                    {
                        flag=true;
                    }
                }
            }
            if(flag)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
        }
        else
        {
            cout<<"1\n";
        }
    }
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
