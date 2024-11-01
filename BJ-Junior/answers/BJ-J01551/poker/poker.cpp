#include<iostream>
#include<cstdio>
using namespace std;
bool data[100][100];
int cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        data[a][b]=1;
    }
    for(int i=1;i<=4;i++){
        char x,y;
        switch(i){
            case 1:x='D';break;
            case 2:x='C';break;
            case 3:x='H';break;
            case 4:x='S';break;
        }
        for(int j=1;j<=13;j++){
            y=j+48;
            switch(j){
                case 1:y='A';break;
                case 10:y='T';break;
                case 11:y='J';break;
                case 12:y='Q';break;
                case 13:y='K';break;
            }
            if(!data[x][y]){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}