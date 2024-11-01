#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string a[53];
    cin>>n;
    string b[53];
    for(int i=1;i<=n;i++)
    {
        b[i]="00";
    }
    int sum=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans++;
        for(int j=1;j<=n;j++)
        {

            if(a[i]==b[j])
            {
                ans--;
                break;
            }
        }
        b[sum]=a[i];
        sum++;

    }
    int cnt=52-ans;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
