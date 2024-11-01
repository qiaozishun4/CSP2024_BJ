#include <bits/stdc++.h>
using namespace std;
int b[1006][1006];
bool count1[1006][1006];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,hang,lie,k,x0,y0,d,cnt;
    char s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cnt=0;
        cin>>hang>>lie>>k;
        cin>>x0>>y0>>d;
        for(int j=1;j<=hang;j++)
        {
            for(int f=1;f<=lie;f++)
            {
                cin>>s;
                if(s=='.')
                {
                    b[j][f]=0;
                    count1[j][f]=false;
                }
                else
                {
                    b[j][f]=1;
                    count1[j][f]=false;
                }
            }
        }
        for(int j=1;j<=k;j++)
        {
            count1[x0][y0]=true;
            if(d==3)
            {
                if(x0-1==0||b[x0-1][y0]==1)
                {
                    d=(d+1)%4;
                }
                else
                {
                    x0-=1;
                }
            }
            else if(d==2)
            {
                if(y0-1==0||b[x0][y0-1]==1)
                {
                    d=(d+1)%4;
                }
                else
                {
                    y0-=1;
                }
            }
            else if(d==1)
            {
                if(x0+1==hang+1||b[x0+1][y0]==1)
                {
                    d=(d+1)%4;
                }
                else
                {
                    x0+=1;
                }
            }
            else
            {
                if(y0+1==lie+1||b[x0][y0+1]==1)
                {
                    d=(d+1)%4;
                }
                else
                {
                    y0+=1;
                }
            }
        }
        count1[x0][y0]=true;
        for(int j=1;j<=hang;j++)
        {
            for(int f=1;f<=lie;f++)
            {
                if(count1[j][f])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
