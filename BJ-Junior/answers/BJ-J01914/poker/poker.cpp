#include<bits/stdc++.h>
using namespace std;
int n;
string s[53];
int t[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //freopen("poker3.in","r",stdin);
    //freopen("poker3.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    unique(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        if(s[i]==""){
            printf("%d",52-(i-1));
            return 0;
        }
    }
    printf("%d",52-n);
    return 0;
}