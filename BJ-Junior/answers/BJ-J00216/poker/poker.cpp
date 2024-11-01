#include<bits/stdc++.h>
using namespace std;
int n,d[90],c[90],h[90],ss[90],ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[0]=='D')
            if(d[s[1]]==0){
                ans++;
                d[s[1]]=1;
            }

        if(s[0]=='C')
            if(c[s[1]]==0){
                ans++;
                c[s[1]]=1;
            }

        if(s[0]=='H')
            if(h[s[1]]==0){
                ans++;
                h[s[1]]=1;
            }

        if(s[0]=='S')
            if(ss[s[1]]==0){
                ans++;
                ss[s[1]]=1;
            }
    }
    cout<<52-ans<<endl;
    return 0;
}