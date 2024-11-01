#include<bits/stdc++.h>
using namespace std;
int n;
char c[2];
int s[5][14],sum=0;
int f(char c){
    if(c=='A'){
        return 1;
    }else if(c=='T'){
        return 10;
    }else if(c=='J'){
        return 11;
    }else if(c=='Q'){
        return 12;
    }else if(c=='K'){
        return 13;
    }else if(c=='2'){
        return 2;
    }else if(c=='3'){
        return 3;
    }else if(c=='4'){
        return 4;
    }else if(c=='5'){
        return 5;
    }else if(c=='6'){
        return 6;
    }else if(c=='7'){
        return 7;
    }else if(c=='8'){
        return 8;
    }else if(c=='9'){
        return 9;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        c[1]=f(c[1]);
        if(c[0]=='D'){
            s[1][c[1]]=1;
        }else if(c[0]=='C'){
            s[2][c[1]]=1;
        }else if(c[0]=='H'){
            s[3][c[1]]=1;
        }else{
            s[4][c[1]]=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(s[i][j]) sum++;
        }
        cout<<endl;
    }
    cout<<52-sum;
    return 0;
}
