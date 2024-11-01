#include<bits/stdc++.h>
using namespace std;
int x,n;
char p[10][60];
bool s[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        s[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            if(s[i]==0){
                x++;
            }
            cout<<52-x;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        if(s[i]==1){
            continue;
        }       
        x++;
        for(int j=i+1;j<=n;j++){
            if(p[j][1]==p[i][1]&&p[j][2]==p[i][2]){
                s[j]=1;
            }
        }
    }
    
}