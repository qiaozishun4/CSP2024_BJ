#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0,ch=getchar();

    while(ch<'0'||ch>'9'){
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c;
}

int n,ans=0;
bool p[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        char a,b;
        int a1=0,b1=0;

        cin>>a>>b;

        if(a=='D'){
            a1=1;
        }else if(a=='C'){
            a1=2;
        }else if(a=='H'){
            a1=3;
        }else if(a=='S'){
            a1=4;
        }

        if(b=='A'){
            b1=1;
        }else if(b=='T'){
            b1=10;
        }else if(b=='J'){
            b1=11;
        }else if(b=='Q'){
            b1=12;
        }else if(b=='K'){
            b1=13;
        }else{
            b1=b-'0';
        }

        p[a1][b1]=1;
    }

    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!p[i][j]){
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}
