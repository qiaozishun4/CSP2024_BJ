#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    char pai[52][2];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>pai[i];
    }
    ans-=n;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (pai[i][0]==pai[j][0]&&pai[i][1]==pai[j][1]&&pai[i][0]!='0')
            {
                ans++;
                pai[j][0]='0';
            }
        }
    }
    cout<<ans;
	return 0;
}
