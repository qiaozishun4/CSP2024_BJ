#include<bits/stdc++.h>
using namespace std;
int b[50][50];
char a[101],c[101];
int f(char x){
    if(x=='A'){
        return 1;
    }else if(x=='2'){
        return 2;

    }else if(x=='3'){
        return 3;

    }else if(x=='4'){
        return 4;

    }else if(x=='5'){
        return 5;

    }else if(x=='6'){
        return 6;

    }else if(x=='7'){
        return 7;

    }else if(x=='8'){
        return 8;

    }else if(x=='9'){
        return 9;

    }else if(x=='T'){
        return 10;

    }else if(x=='J'){
        return 11;

    }else if(x=='Q'){
        return 12;
    }else{
        return 13;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            b[i][j]=0;
        }

    }
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(a[i]=='H'){
            b[1][f(c[i])]=1;
        }else if(a[i]=='C'){
            b[2][f(c[i])]=1;
        }else if(a[i]=='D'){
            b[3][f(c[i])]=1;
        }else if(a[i]=='S'){
            b[4][f(c[i])]=1;
        }
    }for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]==0){
                sum++;
            }
        }

    }

    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
