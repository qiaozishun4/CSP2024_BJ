#include<bits/stdc++.h>
using namespace std;
const int D=1,C=2,H=3,S=4,T=10,J=11,Q=12,K=13,A=14;
int a[150];
bool w[1005];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(!w[s[0]+s[1]])
        {
            w[s[0]+s[1]]=true;
            ans++;
        }
    }
    cout<<52-ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
