#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,answer=1;
        int x,y,d;
        int x1,y1;
        char a[1010][1010];
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int went[k][2];
        went[0][0]=x;
        went[0][1]=y;
        for(int i=0;i<k;i++)
        {
            if(d==0)
            {
                x1=x;
                y1=y+1;
            }else if(d==1)
            {
                x1=x+1;
                y1=y;
            }else if(d==2)
            {
                x1=x;
                y1=y-1;
            }else
            {
                x1=x-1;
                y1=y;
            }
            if((x1>=1 && x1<=n) && (y1>=1 && y1<=m))
            {
                if(a[x1][y1]=='.')
                {
                    x=x1;
                    y=y1;
                }else
                {
                    d=(d+1)%4;
                }
            }else
            {
                d=(d+1)%4;
            }
            int p;
            for(p=0;p<answer;p++)
            {
                if(went[p][0]==x)
                {
                    if(went[p][1]==y)
                    {
                        break;
                    }
                }
            }
            if(p==answer)
            {
                answer++;
                went[p][0]=x;
                went[p][1]=y;
            }
//            cout<<x1<<"/"<<y1<<"/"<<a[x1][y1]<<"/"<<d<<" /  ";
//            cout<<answer<<" 1 ";
//            cout<<x<<" "<<y<<"  ;  ";
        }
        cout<<answer<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}