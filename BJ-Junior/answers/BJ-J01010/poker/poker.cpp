#include<bits/stdc++.h>
using namespace std;
bool arr[5][14];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        string s;
        cin>>s;
        a=s[0],b=s[1];
        if(a=='D'){
            if(b=='A'){
                arr[1][1]=true;
            }else if(b>='2'&&b<='9'){
                arr[1][b-'0']=true;
            }else if(b=='T'){
                arr[1][10]=true;
            }else if(b=='J'){
                arr[1][11]=true;
            }else if(b=='Q'){
                arr[1][12]=true;
            }else if(b=='K'){
                arr[1][13]=true;
            }
        }
        if(a=='C'){
            if(b=='A'){
                arr[2][1]=true;
            }else if(b>='2'&&b<='9'){
                arr[2][b-'0']=true;
            }else if(b=='T'){
                arr[2][10]=true;
            }else if(b=='J'){
                arr[2][11]=true;
            }else if(b=='Q'){
                arr[2][12]=true;
            }else if(b=='K'){
                arr[2][13]=true;
            }
        }
        if(a=='H'){
            if(b=='A'){
                arr[3][1]=true;
            }else if(b>='2'&&b<='9'){
                arr[3][b-'0']=true;
            }else if(b=='T'){
                arr[3][10]=true;
            }else if(b=='J'){
                arr[3][11]=true;
            }else if(b=='Q'){
                arr[3][12]=true;
            }else if(b=='K'){
                arr[3][13]=true;
            }
        }
        if(a=='S'){
            if(b=='A'){
                arr[4][1]=true;
            }else if(b>='2'&&b<='9'){
                arr[4][b-'0']=true;
            }else if(b=='T'){
                arr[4][10]=true;
            }else if(b=='J'){
                    arr[4][11]=true;
            }else if(b=='Q'){
                arr[4][12]=true;
            }else if(b=='K'){
                arr[4][13]=true;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!arr[i][j]){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
