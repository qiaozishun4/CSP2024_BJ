#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,cnt;
string str[105];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>str[i];

    }
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;j<=i-1;j++)
        {
            if(str[j]==str[i])
                flag=false;
        }
        if(flag)
            cnt++;
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
