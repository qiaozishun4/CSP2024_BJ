#include<bits/stdc++.h>
using namespace std;
int stick[26]={0,0,1,7,4,2,0,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        string ans;
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=7;i>=2;i--)
            while((n-i)>=0)
                ans+=char(stick[i]+48),n-=i;
        for(int i=ans.length()-1;i>-1;i--)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
