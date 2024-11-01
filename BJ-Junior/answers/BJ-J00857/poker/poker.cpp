#include<bits/stdc++.h>
using namespace std;
int n,b[101][101],s=0;
string a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='A'){
                b[1][1]=1;
            }
            else if(a[1]=='T'){
                b[1][10]=1;
            }
            else if(a[1]=='J'){
                b[1][11]=1;
            }
            else if(a[1]=='Q'){
                b[1][12]=1;
            }
            else if(a[1]=='K'){
                b[1][13]=1;
            }
            else{
                b[1][a[1]-'0']=1;
            }
        }
        else if(a[0]=='C'){
            if(a[1]=='A'){
                b[2][1]=1;
            }
            else if(a[1]=='T'){
                b[2][10]=1;
            }
            else if(a[1]=='J'){
                b[2][11]=1;
            }
            else if(a[1]=='Q'){
                b[2][12]=1;
            }
            else if(a[1]=='K'){
                b[2][13]=1;
            }
            else{
                b[2][a[1]-'0']=1;
            }
        }
        else if(a[0]=='H'){
            if(a[1]=='A'){
                b[3][1]=1;
            }
            else if(a[1]=='T'){
                b[3][10]=1;
            }
            else if(a[1]=='J'){
                b[3][11]=1;
            }
            else if(a[1]=='Q'){
                b[3][12]=1;
            }
            else if(a[1]=='K'){
                b[3][13]=1;
            }
            else{
                b[3][a[1]-'0']=1;
            }
        }
        else if(a[0]=='S'){
            if(a[1]=='A'){
                b[4][1]=1;
            }
            else if(a[1]=='T'){
                b[4][10]=1;
            }
            else if(a[1]=='J'){
                b[4][11]=1;
            }
            else if(a[1]=='Q'){
                b[4][12]=1;
            }
            else if(a[1]=='K'){
                b[4][13]=1;
            }
            else{
                b[4][a[1]-'0']=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]==0){
                s++;
            }
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
