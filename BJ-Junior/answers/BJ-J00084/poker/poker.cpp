#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int sum=51;
    string a[60];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        string biandong=a[i];
        for (int j=1;j<=n;j++)
        {
            if(a[i]=="wu")
            {
                break;
            }
            if(a[j]=="wu")
            {
                continue;
            }
            if(a[i]!=a[j])
            {
                sum--;
                string s=a[j];
                for (int l=1;l<=n;l++)
                {
                    if(a[l]==s)
                    {
                        a[l]="wu";
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}