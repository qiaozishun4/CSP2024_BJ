#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,cc;
bool flag=false;
char ch1[1000010];
char ch2[1000010];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ch1[i]>>ch2[i];
    if(n==1) {
        cout<<"51"<<endl;
        return 0;
    }
    for(int i=1;i<=1;i++)
        for(int j=i;j<=n;j++)
            if(ch1[i]==ch1[j] && ch2[i]==ch2[j])
                flag=true;
            else
                ans++;
    if(flag)
        ans++;
    cout<<52-ans<<endl;
    return 0;
}
