#include<bits/stdc++.h>
using namespace std;
bool tu[1010][1010]={};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        bool biao[1010][1010]={};
        int cnt=1;
        int n,m,k;
        cin >>n>>m>>k;
        int x,y,d;
        cin >>x>>y>>d;
        biao[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int q=1;q<=m;q++){
                char w;
                cin >> w;
                if(w=='.')tu[j][q]=1;
                else tu[j][q]=0;
            }
        }
        for(int j=1;j<=k;j++){
            if(d==0)y+=1;
            else if(d==1)x+=1;
            else if(d==2)y-=1;
            else x-=1;
            //cout << d0 << endl;
            if((x>=1)&&(y>=1)&&(x<=n)&&(y<=m)&&(tu[x][y]==1)){
                if(biao[x][y]==0){
                   cnt++;
                   biao[x][y]=1;
                   //cout << "("<<x<<","<<y<<")"<<endl;
                }

                //cout << "("<<x<<","<<y<<")"<<endl;
            }
            else{
                if(d==0)y-=1;
                else if(d==1)x-=1;
                else if(d==2)y+=1;
                else x+=1;
                d=((d+1)%4);

            }
        }
        cout <<cnt<<endl;
    }
    return 0;
}
