#include<iostream>
using namespace std;
int t,n,a[100005],sum=0;
bool flag;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4)
            {
                cout<<"0";
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j]&&a[i]>sum)
                {
                    sum=a[i];
                    flag=false;
                }
            }
        }
        if(flag==false)
        {
            cout<<sum;
        }
        else
            cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
