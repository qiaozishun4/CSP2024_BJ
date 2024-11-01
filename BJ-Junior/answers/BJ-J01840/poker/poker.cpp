#include <bits/stdc++.h>
using namespace std;
int f(char c){
    switch(c){
        case 'D':
        return 1;
        case 'C':
        return 2;
        case 'H':
        return 3;
        case 'S':
        return 4;
    }
}

int g(char c){
    if(c>='2'&&c<='9'){
        return (c-'0');
    }else if(c=='A'){
        return 1;
    }else if(c=='T'){
        return 10;
    }else if(c=='J'){
        return 11;
    }else if(c=='Q'){
        return 12;
    }else if(c=='K'){
        return 13;
    }
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    bool a[5][15]={};
    char c,d;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c >> d;
        int typec=f(c);
        int typed=g(d);
        a[typec][typed]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==false){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
