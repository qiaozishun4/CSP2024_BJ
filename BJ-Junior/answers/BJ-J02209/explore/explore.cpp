#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    char expl[1005][1005];
    int T;
    cin>>T;
    for (int i=0; i<T; i++){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1; j<=n; j++){
            for(int o=1; o<=m; o++){
                cin>>expl[j][o];
            }
        }
        expl[x][y]='k';
        //input fin
        int newx, newy, res=0;
        for (int j=1; j<=k; j++){

            if(d==0){newx=x;newy=y+1;}
            if(d==1){newx=x+1;newy=y;}
            if(d==2){newx=x;newy=y-1;}
            if(d==3){newx=x-1;newy=y;}

            if(!(1<=newx&&newx<=n&&1<=newy&&newy<=m && expl[newx][newy]!='x')){
                if(d==3)d=0;
                else d++;
                newx=x;
                newy=y;
            }else{
                expl[newx][newy]='k';
                x=newx;
                y=newy;
            }
        }
        for(int j=1; j<=n; j++){
            for(int k=1; k<=m; k++){
                if(expl[j][k]=='k')
                    res++;
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
