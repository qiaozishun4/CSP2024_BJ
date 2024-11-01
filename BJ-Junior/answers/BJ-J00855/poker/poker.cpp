#include<bits/stdc++.h>
using namespace std;
bool a[60];
int n,cnt;
int poker(char s){
    if(s<='9'){
        return(s-'0');
    }
    else{
        switch(s){
            case 'J':return 11;
            case 'Q':return 12;
            case 'K':return 13;
            case 'T':return 10;
            case 'A':return 1;
        }
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        if(s[0]=='D'){
            a[poker(s[1])]=1;
        }
        else if(s[0]=='C'){
            a[poker(s[1])+13]=1;
        }
        else if(s[0]=='H'){
            a[poker(s[1])+26]=1;
        }
        else{
            a[poker(s[1])+39]=1;
        }
    }
    for(int i=1;i<=52;i++){
        if(!a[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
