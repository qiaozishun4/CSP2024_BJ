#include<bits/stdc++.h>
using namespace std;
bool a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        cin>>x>>y;
        int cnt=0;
        if(x=='C')cnt+=13;
        else if(x=='H')cnt+=26;
        else if(x=='S')cnt+=39;
        if(y=='A')cnt++;
        else if(y=='T')cnt+=10;
        else if(y=='J')cnt+=11;
        else if(y=='Q')cnt+=12;
        else if(y=='K')cnt+13;
        else cnt+=y-'0';
        if(a[cnt]==0){
            ans--;
            a[cnt]=1;
        }
    }
    cout<<ans;
    return 0;
}