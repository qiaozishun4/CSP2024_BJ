#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int len(int n)
{
    int cnt=0;
    while(n)
    {
        cnt++;
        n=n/10;
    }
    return pow(10,cnt);
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int x=0;x<T;x++)
    {
        int n;
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        int w[6]={6,2,5,4,3,7};
        int p[6]={0,1,2,4,7,8};
        int f[100002]={0,0,1,7,4,2,0,8};//wu 6
        int m[100002]={0,0,1,7,4,2,6,8};//dui wai
        for(int i=8;i<=n;i++)
        {
            int minjf=0x3f3f3f;
            int minjm=0x3f3f3f;
            int com[6]={};
            int wr[6]={};
            for(int j=0;j<6;j++)
            {
                if(i-w[j]<2)
                    continue;
                com[j]=f[i-w[j]];
                wr[j]=com[j];
                if(p[j]==0)
                    com[j]+=6*len(m[i-w[j]]);
                else
                    com[j]+=p[j]*len(m[i-w[j]]);
                wr[j]+=p[j]*len(m[i-w[j]]);
                if(com[j]<minjm)
                {
                    minjm=com[j];
                    minjf=wr[j];
                }
            }
            f[i]=minjf;
            m[i]=minjm;
        }
        cout<<m[n]<<endl;
    }
    fclose("sticks.in");
    fclose("sticks.out");
    return 0;
}