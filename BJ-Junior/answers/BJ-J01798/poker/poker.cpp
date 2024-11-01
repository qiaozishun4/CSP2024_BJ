#include <bits/stdc++.h>
using namespace std;
string t[100];
int res;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        cin>>t[i];
    }
    sort(t+1,t+n+1);
    for(int i = 1;i<=n;i++){
        if(t[i]!=t[i-1])res++;
    }
    printf("%d",52-res);

    return 0;
}
