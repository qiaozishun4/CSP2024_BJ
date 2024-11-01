#include<bits/stdc++.h>
using namespace std;
int n,top,flag,cnt;
char c[5];
struct poke{
    char ch[5];
    int num=0;
}a[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",c);
        for(int j=0;j<top;j++){
            if(a[j].ch[0]==c[0]&&a[j].ch[1]==c[1]){
                flag=1;
            }
        }
        if(flag==0){
            a[top].ch[0]=c[0];
            a[top].ch[1]=c[1];
            a[top].num++;
            top++;
            cnt++;
        }
        flag=0;
    }
    int res=52-cnt;
    printf("%d",res);
    return 0;
}