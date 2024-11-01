#include<bits/stdc++.h>
using namespace std;
int st[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=2e9;
        for(int i=1;i<=1e6;i++){
            int x=i,s=0;
            while(x){
                s+=st[x%10];
                x/=10;
            }
            if(s!=n)continue;
            m=min(m,i);
        }
        if(m==2e9)cout<<-1;
        else cout<<m;
        cout<<endl;
    }
    return 0;
}
