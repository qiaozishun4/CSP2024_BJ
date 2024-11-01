#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a[14] = {"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
    int b[4][14] = {0};
    int g;
    string c = " ";
    cin>>g;
    for(int i = 1;i<=g;i++){
        cin>>c;
        if("D"<c && c <"E"){
            for (int j = 0 ;j<13;j++){
                if(c == "D"+a[j]){
                    b[0][j]+=1;
                    break;
                    }
                }
            }
        else if("C"<c && c <"D"){
            for (int j = 0 ;j<13;j++){
                if(c == "C"+a[j]){
                    b[1][j]+=1;
                    break;
                    }
                }
            }
        else if("H"<c && c <"I"){
            for (int j = 0 ;j<13;j++){
                if(c == "H"+a[j]){
                    b[2][j]+=1;
                    break;
                    }
                }
            }
        else if("S"<c && c <"T"){
            for (int j = 0 ;j<13;j++){
                if(c == "S"+a[j]){
                    b[3][j]+=1;
                    break;
                    }
                }
            }
        }
    int q = 0,ans = 0;
    for(int i = 0;i<=3;i++){
        for(int j = 0; j<13;j++){
        if(b[i][j] >= 1){
            q+=1;
            }
        }
    }
    ans = 52-q;
    cout<<ans;
    return 0;
    }
