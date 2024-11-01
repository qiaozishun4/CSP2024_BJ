#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,x,y,d,cnt=0;
char map[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,a[20];
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
            cin>>map[j][k];
            }
        }
        while(k!=0){
            k--;
            cout<<d<<"   "<<cnt<<endl;
            if(d==0)
            {
                y=y+1;
                if(y>m||map[x][y]=='x')
                {
                    d=(d+1)%4;
                    y=y-1;
                }
                else
            {
                cnt++;
            }
            }
            else if(d==1)
            {
                    x=x+1;
                    if(x>n||map[x][y]=='x')
                    {
                        d=(d+1)%4;
                        x=x-1;
                    }
                    else
                    {
                    cnt++;
                    }
            }
            else if(d==2)
            {
                y=y-1;
                if(y<=0||map[x][y]=='x')
                {
                    d=(d+1)%4;
                    y=y+1;
                }
                else
                {
                cnt++;
                }
            }
            else if(d==3)
            {
                x=x-1;
                if(x<=0||map[x][y]=='x')
                {
                    d=(d+1)%4;
                    x=x+1;
                }
                else
                {
                cnt++;
                }
            }
    }
    cout<<cnt<<endl;
    cnt=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
