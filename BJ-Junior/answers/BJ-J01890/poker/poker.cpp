#include <bits/stdc++.h>
using namespace std;

const int N=10,M=100;
bool vis[N][M];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c1,c2;
        cin>>c1>>c2;
        int num;
        if(c2>='2' && c2<='9'){
            num=c2-'0';
        }else{
            switch(c2){
                case 'A':
                    num=1;
                    break;
                case 'T':
                    num=10;
                    break;
                case 'J':
                    num=11;
                    break;
                case 'Q':
                    num=12;
                    break;
                default:
                    num=13;
                    break;
            }
        }
        switch(c1){
            case 'D':
                if(!vis[1][num]){
                    vis[1][num]=true;
                    cnt++;
                }
                break;
            case 'C':
                if(!vis[2][num]){
                    vis[2][num]=true;
                    cnt++;
                }
                break;
            case 'H':
                if(!vis[3][num]){
                    vis[3][num]=true;
                    cnt++;
                }
                break;
            default:
                if(!vis[4][num]){
                    vis[4][num]=true;
                    cnt++;
                }
                break;
        }
    }
    if(cnt>=52){
        cout<<0<<endl;
    }else{
        cout<<52-cnt<<endl;
    }
    return 0;
}

