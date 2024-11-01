#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
char s[10];
bool a[505][505];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[0]>>s[1];
        int x=s[0],y=s[1];
        if(a[x][y]==0){
            a[x][y]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
