#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[200][200];
char x[5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%s",x);
        if(a[x[0]][x[1]]==0){
            cnt++;
        }
        a[x[0]][x[1]]=1;
    }
    cout<<52-cnt;
    return 0;
}