#include<bits/stdc++.h>
using namespace std;
int h[60];
int tf(char a){
    switch(a){
        case 'D':
            return 0;
        case 'C':
            return 1;
        case 'H':
            return 2;
        case 'S':
            return 3;
    }
    return -1;
}
int ts(char a){
    switch(a){
        case 'A':
            return 0;
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        case '9':
            return 8;
        case 'T':
            return 9;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
    }
    return -1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        cin>>x>>y;
        h[tf(x)*13+ts(y)]=1;
    }
    int ans=0;
    for(int i=0;i<52;i++){
        if(!h[i])   ans++;
    }
    cout<<ans;
    return 0;
}
