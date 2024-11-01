#include<bits/stdc++.h>
using namespace std;
int oooo;
int n;
int a[200005],t[200005];
bool f[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>oooo;
    while(oooo--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(f,false,sizeof(f));
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(f[a[i]]==true)
            {
                num+=a[i];
                f[a[i]]=false;
            }
            else f[a[i]]=true;
        }
        cout<<num<<endl;
    }
}
