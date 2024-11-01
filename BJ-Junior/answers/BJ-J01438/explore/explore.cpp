#include<bits/stdc++.h>
using namespace std;
int n,a,b,sum,x,y,d,c[1010][1010],u[1010][1010],s;
int k(int e,int f,int g,int w)
{
    if(w<=0)
    {
        return 0;
    }
    if(g==0)
    {
        if(c[e][f+1]==1&&f<b)
        {
            u[e][f+1]=1;
            k(e,f+1,g,w-1);

        }
        else
        {
            k(e,f,(g+1)%4,w-1);
        }
    }
    if(g==1)
    {
        if(c[e+1][f]==1&&e<a)
        {
            u[e+1][f]=1;
            k(e+1,f,g,w-1);
        }
        else
        {
            k(e,f,(g+1)%4,w-1);
        }
    }

    if(g==2)
    {
        if(c[e][f-1]==1&&f>1)
        {
            u[e][f-1]=1;
            k(e,f-1,g,w-1);
        }
        else
        {
            k(e,f,(g+1)%4,w-1);
        }
    }
    if(g==3)
    {
        if(c[e-1][f]==1&&e>1)

        {
            u[e-1][f]=1;
            k(e-1,f,g,w-1);
        }
        else
        {
            k(e,f,(g+1)%4,w-1);
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //freopen("explore.in","w",stdin);
    cin>>n;
    for(int o=1;o<=n;o++)
    {
        for(int p=1;p<=1009;p++)
        {
           for(int nm=1;nm<=1009;nm++)
            {
                u[p][nm]=0;
            }
        }
        for(int p=1;p<=1009;p++)
        {
           for(int nm=1;nm<=1009;nm++)
            {
                c[p][nm]=0;
            }
        }
        cin>>a>>b>>sum>>x>>y>>d;
        u[x][y]=1;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                char s;
                cin>>s;
                if(s=='.')
                {
                    c[i][j]=1;
                }
                else
                {
                    c[i][j]=0;
                }
            }
        }
        k(x,y,d,sum);
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(u[i][j]==1)
                    s++;
            }
        }
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
