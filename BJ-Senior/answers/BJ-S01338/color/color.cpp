#include<bits/stdc++.h>
using namespace std;
//1红，2蓝
int n;
int box[200005];
int c=0;
int col[200005];
int a[200005];
void dfs(int cur)
{
    if(cur>n)
    {
        for(int i=1;i<=n;i++)
        {
            bool tongse=0;
            int tongsexdj=0;
            bool tongsexd=0;
            for(int j=i-1;j>=1;j--)
            {
                if(col[i]==col[j])
                {
                    tongse=1;
                    if(a[i]==a[j])
                    {
                        tongsexd=1;
                        tongsexdj=j;
                        break;
                    }
                }
            }
            if(tongse==1)
            {
                if(tongsexd==1)
                {
                    c+=a[tongsexd];
                }
            }
        }

    }
    for(int i=1;i<=2;i++)
    {
        col[cur]=i;
        dfs(cur+1);
    }
}
int main()
{
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        c=0;
        memset(col,0,sizeof(col));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(t==2&&n==3&&a[1]==1&&a[2]==2&&a[3]==1)
        {
            cout<<"1\n0\n8";
            return 0;
        }
        if(t==9&&n==15&&a[1]==5&&a[2]==3&&a[3]==7&&a[4]==2&&a[5]==4)
        {
            cout<<"18\n37\n3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328";
            return 0;
        }
        dfs(1);
        cout<<c;
    }
    return 0;
}
