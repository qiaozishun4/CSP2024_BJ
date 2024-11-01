#include<bits/stdc++.h>
using namespace std;
struct poker{
    string s;
}a[10000],b[10000];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=cnt;j++){
            if(a[i].s==b[j].s){
                flag=0;
            }
        }
        if(flag){
            b[++cnt]=a[i];
        }
    }
    cout<<52-cnt;
    return 0;
}
