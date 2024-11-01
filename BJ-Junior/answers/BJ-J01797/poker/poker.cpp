#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        if(mp[x]==0)
        {
            mp[x]++;
            cnt++;
        }
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
