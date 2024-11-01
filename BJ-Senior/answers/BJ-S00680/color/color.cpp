#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.ans","w",stdout);
    int T;
    cin>>T;
    for(int k=0; k<T; k++)
    {
        int a[100005];
        bool A[100005];
        int c[100005];
        int s=0;
        int sum=0;
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum++;
        }
        for(int i=0; i<sum; i++)
        {
            A[i]=1;
        }
        for(int b=0; b<n; b++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    A[b]=0;
                    if(A[i-j]!=0)
                    {
                        c[i]=0;
                    }
                    if(A[i]-A[i-j]<0&&a[i]==a[i-j])
                    {
                        c[i]=a[i];
                    }
                    else
                    {
                        c[i]=0;
                    }
                }
            }
            for(int i=0; i<n; i++)
            {
                s=s+c[i];
            }
            cout<<s;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
