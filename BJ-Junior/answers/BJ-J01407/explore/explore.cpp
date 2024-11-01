#include<bits/stdc++.h>

using namespace std;

int mapp[1003][1003]={};
int T,m,n,k,ans[6]={};
int main (){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>T;

    for(int c=0;c<T;c++){

        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char q;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                cin>>q;

                if(q=='x'){

                    mapp[i][j]=1;
                }
            }
        }

        mapp[x][y]=-1;

        for(int i=1;i<=k;i++){

            if(d==0){

                if(y+1<=m&&y+1>=1&&x>=1&&x<=n&&mapp[x][y+1]!=1){

                    y++;
                    mapp[x][y]=-1;
                }

                else{

                    d=1;
                }
            }

            else if(d==1){

                if(y<=m&&y>=1&&x+1>=1&&x+1<=n&&mapp[x+1][y]!=1){

                    x++;
                    mapp[x][y]=-1;
                }

                else{

                    d=2;
                }
            }

            else if(d==2){

                if(y-1<=m&&y-1>=1&&x>=1&&x<=n&&mapp[x][y-1]!=1){

                    y--;
                    mapp[x][y]=-1;
                }

                else{

                    d=3;
                }
            }

            else if(d==3){

                if(y<=m&&y>=1&&x-1>=1&&x-1<=n&&mapp[x-1][y]!=1){

                    x--;
                    mapp[x][y]=-1;
                }

                else{

                    d=0;
                }
            }
        }

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(mapp[i][j]==-1){

                    ans[c]++;
                }
                mapp[i][j]=0;
            }
        }
    }

    for(int i=0;i<T;i++){

        cout<<ans[i]<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
