#include<iostream>
using namespace std;
int s[1000][1000];
int l[1001];
int r[1001],c[1001];
int aswer[10001];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,k,q;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l[j];
            for(int p=1;p<=l[j];p++)
            {
                cin>>s[j][p];
            }
        }
        for(int j=1;j<=q;j++)
        {
            cin>>r[j]>>c[j];
            int sum=0;
            for(int w=1;w<=n;w++)
            {
                for(int p=1;p<=l[j];p++)
                {
                    if(s[w][p]==c[j])
                    {
                        sum=1;
                    }
                }
            }
            if(sum==1)
            {
                aswer[j+(i-1)*q]=1;
            }
            else
            {

               aswer[j+(i-1)*q]=0;
            }
        }
    }
    for(int i=1;i<=t*q;i++)
    {
        cout<<aswer[i]<<endl;
    }
    return 0;
}
