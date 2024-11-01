#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int vis=0;
    char a[120];
    cin>>n;
    if(n==1){
        cout<<51;
        return 0;
    }

    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=2*n;j+=2){
        for(int i=j+2;i<=2*n;i+=2){
            if(a[j]==a[i]&&a[i+1]==a[j+1]&&a[i]!=0&&a[i+1]!=0){
                vis+=1;
                a[i]=0;
                a[i+1]=0;
            }
        }
    }
    cout<<52-n+vis;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
