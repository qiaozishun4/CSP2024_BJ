#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool flag[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c,x;
        cin>>c>>x;
        switch(c){
        case 'D':
            switch(x){
            case 'T':
                if(flag[0][9]==0){
                    ans--;flag[0][9]=1;
                }
                break;
            case 'J':
                if(flag[0][10]==0){
                    ans--;flag[0][10]=1;
                }
                break;
            case 'Q':
                if(flag[0][11]==0){
                    ans--;flag[0][11]=1;
                }
                break;
            case 'K':
                if(flag[0][12]==0){
                    ans--;flag[0][12]=1;
                }
                break;
            case 'A':
                if(flag[0][0]==0){
                    ans--;flag[0][0]=1;
                }
                break;
            default:
                if(flag[0][x-'0'-1]==0){
                    ans--;flag[0][x-'0'-1]=1;
                }
                break;
            }
            break;
        case 'C':
            switch(x){
            case 'T':
                if(flag[1][9]==0){
                    ans--;flag[1][9]=1;
                }
                break;
            case 'J':
                if(flag[1][10]==0){
                    ans--;flag[1][10]=1;
                }
                break;
            case 'Q':
                if(flag[1][11]==0){
                    ans--;flag[1][11]=1;
                }
                break;
            case 'K':
                if(flag[1][12]==0){
                    ans--;flag[1][12]=1;
                }
                break;
            case 'A':
                if(flag[1][0]==0){
                    ans--;flag[1][0]=1;
                }
                break;
            default:
                if(flag[1][x-'0'-1]==0){
                    ans--;flag[1][x-'0'-1]=1;
                }
                break;
            }
            break;
        case 'H':
            switch(x){
            case 'T':
                if(flag[2][9]==0){
                    ans--;flag[2][9]=1;
                }
                break;
            case 'J':
                if(flag[2][10]==0){
                    ans--;flag[2][10]=1;
                }
                break;
            case 'Q':
                if(flag[2][11]==0){
                    ans--;flag[2][11]=1;
                }
                break;
            case 'K':
                if(flag[2][12]==0){
                    ans--;flag[2][12]=1;
                }
                break;
            case 'A':
                if(flag[2][0]==0){
                    ans--;flag[2][0]=1;
                }
                break;
            default:
                if(flag[2][x-'0'-1]==0){
                    ans--;flag[2][x-'0'-1]=1;
                }
                break;
            }
            break;
        case 'S':
            switch(x){
            case 'T':
                if(flag[3][9]==0){
                    ans--;flag[3][9]=1;
                }
                break;
            case 'J':
                if(flag[3][10]==0){
                    ans--;flag[3][10]=1;
                }
                break;
            case 'Q':
                if(flag[3][11]==0){
                    ans--;flag[3][11]=1;
                }
                break;
            case 'K':
                if(flag[3][12]==0){
                    ans--;flag[3][12]=1;
                }
                break;
            case 'A':
                if(flag[3][0]==0){
                    ans--;flag[3][0]=1;
                }
                break;
            default:
                if(flag[3][x-'0'-1]==0){
                    ans--;flag[3][x-'0'-1]=1;
                }
                break;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}
