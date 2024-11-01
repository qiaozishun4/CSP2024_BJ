#include<iostream>
#include<cstdio>
using namespace std;
int n;
char c[55][5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int tot=0,p=n;
    for(int i=0;i<n;i++){
        char s[2];
        cin>>s;
        int flag=1;
        for(int j=0;j<=tot;j++){
            if(c[j][0]==s[0]&&c[j][1]==s[1]){
                flag=0;
                break;
            }
        }
        if(flag){
            c[++tot][0]=s[0];
            c[tot][1]=s[1];
        }
        else p--;
    }
    cout<<52-p;
    return 0;
}
