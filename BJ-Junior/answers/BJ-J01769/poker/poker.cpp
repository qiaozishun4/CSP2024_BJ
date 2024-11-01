#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200][200];
char b[]={'D','C','H','S'},c[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[s[0]][s[1]]++;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[b[i]][c[j]]==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}
