#include<bits/stdc++.h>
using namespace std;
int a[53],n,ans=0,b=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string c;
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        switch(c[0]){
            case 'S':b=0;break;
            case 'C':b=13;break;
            case 'D':b=26;break;
            case 'H':b=39;break;
        }
        switch(c[1]){
            case 'T':a[b+10]++;break;
            case 'J':a[b+11]++;break;
            case 'Q':a[b+12]++;break;
            case 'K':a[b+13]++;break;
            case 'A':a[b+1]++;break;
            default:{
                a[b+int(c[1]-'0')]++;
                break;
            }
        }
    }
    for(int i=1;i<=52;i++)
        if(a[i]==0)ans++;
    cout<<ans;
    return 0;
}