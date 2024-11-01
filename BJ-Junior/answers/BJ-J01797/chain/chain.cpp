#include<bits/stdc++.h>
using namespace std;
int a[1010][2010];
int l[2010];
vector<int> p[2010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                {
                    p[i].push_back(j);
                }
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(r==1)
            {
                bool flag=false;
                for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<p[i].size();j++)
                    {
                        for(int k=p[i][j]+1;k<=(p[i][j]+m-1)&&k<=n;k++)
                        {
                            if(a[i][k]==c)
                            {
                                flag=true;
                                cout<<1<<endl;
                                break;
                            }
                        }
                        if(flag==true)
                        {
                            break;
                        }
                    }
                    if(flag==true)
                    {
                        break;
                    }
                }
                if(flag==false)
                {
                    cout<<0<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
