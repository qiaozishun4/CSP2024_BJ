#include <iostream>

using namespace std;
int T,n,m,k;
int x,y,d;
bool arr[1000][1000];
char arrr[1000][1000];
void cancel(int n1,int m1)
{
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            arr[i][j]=0;
        }
    }
    return;
}
void  mov(int x,int y,int d,int k)
{
    arr[x][y]=1;
    if(k==0)
    {
        return;
    }
    if(d==0&&arrr[x][y+1]=='.'&&y+1<m)
    {
        mov(x,y+1,d,k-1);
        return;
    }
    if(d==1&&arrr[x+1][y]=='.'&&x+1<n)
    {
        mov(x+1,y,d,k-1);
        return;
    }
    if(d==2&&arrr[x][y-1]=='.'&&y-1>=0)
    {
        mov(x,y-1,d,k-1);
        return;
    }
    if(d==3&&arrr[x-1][y]=='.'&&x-1>=0)
    {
        mov(x-1,y,d,k-1);
        return;
    }
    else
    {
        d=(d+1)%4;
        mov(x,y,d,k-1);
        return;
    }
}

int cou(int n1,int m1)
{
    int sum=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            if(arr[i][j]==1)
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    int ans[T];
    for(int i=0;i<T;i++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        cancel(n,m);
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arrr[i][j];
            }
        }
        mov(x-1,y-1,d,k);
        ans[i]=cou(n,m);
    }
    for(int i=0;i<T;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}



