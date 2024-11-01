#include<iostream>
using namespace std;
int a[10][15];
char d,f;
int sum,q=1,w=12,e=11,r=13,p=10;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>f;
        int g=0;
         if(f=='A'){
            g=q;
        }else if(f=='Q'){
            g=w;
        }else if(f=='J'){
            g=e;
        }else if(f=='K'){
            g=r;
        }else if(f=='T'){
            g=p;
        }
        if(g==0){
          g=int(f)-48;
        }
        if(d=='D'){
            a[1][g]++;
        }else if(d=='C'){
            a[2][g]++;
        }else if(d=='H'){
            a[3][g]++;
        }else if(d=='S'){
            a[4][g]++;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
               sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

