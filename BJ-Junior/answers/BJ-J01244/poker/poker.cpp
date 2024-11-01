#include<bits/stdc++.h>
using namespace std;
bool vis[10][28];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        string s;
        cin>>s;
        switch(s[1]){
            case 'A':a=1;break;
            case '2':a=2;break;
            case '3':a=3;break;
            case '4':a=4;break;
            case '5':a=5;break;
            case '6':a=6;break;
            case '7':a=7;break;
            case '8':a=8;break;
            case '9':a=9;break;
            case 'T':a=10;break;
            case 'J':a=11;break;
            case 'Q':a=12;break;
            case 'K':a=13;break;
        }
        switch(s[0]){
            case 'D':b=1;break;
            case 'C':b=2;break;
            case 'H':b=3;break;
            case 'S':b=4;break;
        }
        vis[b][a]=1;
    }
    int sum=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j])sum++;
        }
    }
    cout<<sum;
    return 0;
}
