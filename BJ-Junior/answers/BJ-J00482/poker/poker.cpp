#include <iostream>
#include <string>
using namespace std;
bool p[60];
int n,a=52,t;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    for(int i=0;i<60;++i)p[i]=true;
    cin>>n;
    for(int i=0;i<n;++i){
        t=0;
        cin>>s;
        switch(s[0]){
            case 'C':
                t+=13;
                break;
            case 'H':
                t+=26;
                break;
            case 'S':
                t+=39;
                break;
        }
        switch(s[1]){
            case 'A':
                t+=1;
                break;
            case '2':
                t+=2;
                break;
            case '3':
                t+=3;
                break;
            case '4':
                t+=4;
                break;
            case '5':
                t+=5;
                break;
            case '6':
                t+=6;
                break;
            case '7':
                t+=7;
                break;
            case '8':
                t+=8;
                break;
            case '9':
                t+=9;
                break;
            case 'T':
                t+=10;
                break;
            case 'J':
                t+=11;
                break;
            case 'Q':
                t+=12;
                break;
            case 'K':
                t+=13;
                break;
        }
        if(p[t]){
            --a;
            p[t]=false;
        }
    }
    cout<<a<<endl;
    return 0;
}
