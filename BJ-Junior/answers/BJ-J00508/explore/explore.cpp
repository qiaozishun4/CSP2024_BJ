#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,d,t,k,cnt;
char ch[100001][100001];
char ch2[100001][100001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ch[i][j];
                ch2[i][j]=ch[i][j];
            }
        }
        while(k--){
            for(int i=x;i<=n;i++){
            for(int j=y;j<=m;j++){
                    if(d==0){
                        j++;
                        if(ch[i][j]!='x'&&ch2[i][j]!='0'){
                            cnt++;
                            ch2[i][j]=='0';
                        }
                    }
                    else if(d==1){
                        i++;
                        if(ch[i][j]!='x'&&ch2[i][j]!='0'){
                            cnt++;
                            ch2[i][j]=='0';
                        }
                    }
                    else if(d==2){
                        j++;
                        if(ch[i][j]!='x'&&ch2[i][j]!='0'){
                            cnt++;
                            ch2[i][j]=='0';
                        }
                    }
                    else if(d==3){
                        i--;
                        if(ch[i][j]!='x'&&ch2[i][j]!='0'){
                            cnt++;
                            ch2[i][j]=='0';
                        }
                    }

            }
        }
        }
    printf("%d",cnt);
    }


    return 0;
}
