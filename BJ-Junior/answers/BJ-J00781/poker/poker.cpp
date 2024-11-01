#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int ans[5][20];
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        a=getchar();
        while(a<'A'||a>'Z')a=getchar();
        b=getchar();
        int x=0,y=0;
        switch(a){
            case 'D':{x=1;break;}
            case 'C':{x=2;break;}
            case 'H':{x=3;break;}
            case 'S':{x=4;break;}
            default :break;
        }
        switch(b){
            case 'A':{y=1;break;}
            case '2':{y=2;break;}
            case '3':{y=3;break;}
            case '4':{y=4;break;}
            case '5':{y=5;break;}
            case '6':{y=6;break;}
            case '7':{y=7;break;}
            case '8':{y=8;break;}
            case '9':{y=9;break;}
            case 'T':{y=10;break;}
            case 'J':{y=11;break;}
            case 'Q':{y=12;break;}
            case 'K':{y=13;break;}
            default :break;
        }
        ans[x][y]++;
    }
    int an=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(ans[i][j]==0)an++;
        }
    }
    cout<<an;
    return 0;
}
