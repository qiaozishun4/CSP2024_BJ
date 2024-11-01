#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
int flag=-1;
struct P{
    char h;
    char num;
}p[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>p[i].h>>p[i].num;
        for(int j=1;j<=i;j++){
            if(p[i].h==p[j].h&&p[i].h==p[j].h){
                flag==0;
            }else{
                flag=1;
            }
        }
        if(flag==1){
            ans--;
        }
    }
     if(n==1){
        cout<<51;
    }else{
        printf("%d",ans);
    }

    return 0;
}