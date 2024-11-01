#include<bits/stdc++.h>
using namespace std;

int t,n[20],mxn=0;
int op[10]={6,2,5,5,4,5,6,3,7,6};
string f[100005];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
        mxn=max(n[i],mxn);
    }
    for(int i=0;i<=mxn;i++)
    {
        f[i]="0";
    }
    for(int i=1;i<=mxn;i++)
    {
        bool ff=true;
        for(int j=0;j<=9;j++)
        {
            if(i-op[j]==0)
            {
                if(ff)
                {
                    f[i]=j+'0';
                    ff=false;
                }
                else
                {
                    if(f[i].size()>1)
                    {
                        f[i]=j+'0';
                    }
                    else if(f[i].size()==1)
                    {
                        string s;
                        s=(char)(j+'0');
                        f[i]=min(f[i],s);
                    }
                }
            }
            else if(i-op[j]>0)
            {
                if(f[i-op[j]][0]!='0')
                {
                    if(ff)
                    {
                        f[i]=f[i-op[j]]+(char)(j+'0');
                        ff=false;
                    }
                    else
                    {
                        if(f[i].size()<f[i-op[j]].size()+1)
                        {
                            continue;
                        }
                        else if(f[i].size()>f[i-op[j]].size()+1)
                        {
                            f[i]=f[i-op[j]]+(char)(j+'0');
                        }
                        else f[i]=min(f[i],f[i-op[j]]+(char)(j+'0'));
                    }
                }
            }
        }
        if(i==6)f[i]="6";
    }
    for(int i=1;i<=t;i++)
    {
        if(f[n[i]][0]!='0')cout<<f[n[i]]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
