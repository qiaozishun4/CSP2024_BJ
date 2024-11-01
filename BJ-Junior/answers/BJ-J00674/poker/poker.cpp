#include<bits/stdc++.h>
using namespace std;
map<string,int>m;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int sum=52;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(m[s]<4)
        {
            sum--;
            m[s]++;

        }
    }
    cout<<sum;
    return 0;
}
