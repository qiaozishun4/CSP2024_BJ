#include<iostream>
using namespace std;
int n,cnt;
string s[55];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        cnt++;
        for(int j=1;j<i;j++)
            if(s[j]==s[i])
                cnt--;
    }
    cout<<52-cnt;
    return 0;
}
