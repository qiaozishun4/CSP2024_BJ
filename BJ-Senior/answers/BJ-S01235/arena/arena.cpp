#include <bits/stdc++.h>//just game
using namespace std;
int gr(int l,int r){
    return rand()%(r+l-1)+l;
}
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n;
char a[105][105];
void pm(){//print map
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
struct node{
    int x,y;
};
int main(){
    srand(time(0));
    while (1){
        memset(a,'.',sizeof a);
        queue<node> q;
        cout<<"size:";
        string s;
        cin>>s;
        int w,r;
        if (s=="small"){
            n=9;
            w=20;
            r=1;
        }
        if (s=="middle"){
            n=15;
            w=30;
            r=2;
        }
        if (s=="big"){
            n=23;
            w=45;
            r=4;
        }
        for (int i=1;i<=r;i++){
            int x=gr(1,n),y=gr(1,n);
            while (x==1&&y==1||x==n&&y==n||a[x][y]!='.') x=gr(1,n),y=gr(1,n);
            a[x][y]='x';
            q.push(node{x,y});
        }
        for (int i=1;i<=w;i++){
            int x=gr(1,n),y=gr(1,n);
            while (x==1&&y==1||x==n&&y==n||a[x][y]!='.') x=gr(1,n),y=gr(1,n);
            a[x][y]='w';
        }
        //pm();
        q.push(node{-1,-1});
        int nx=n,ny=n;
        int bflag=0;
        while (!q.empty()){
            int flag=0;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (i==1&&j==1){
                        cout<<'e';
                        if (nx==1&&ny==1){

                            flag=1;
                        }
                    }
                    else if (nx==i&&ny==j){
                        if (a[nx][ny]=='x'){

                            flag=2;
                        }
                        cout<<'o';
                    }
                    else{
                        cout<<a[i][j];
                    }
                }
                cout<<endl;
            }
            if (flag){
                if (flag==1) cout<<"YOU WIN!"<<endl;
                else cout<<"GAME OVER!"<<endl;
                break;
            }
            int temx=nx,temy=ny;
            char op;
            cin>>op;
            if (op=='r') break;
            if (op=='a') ny--;
            if (op=='w') nx--;
            if (op=='s') nx++;
            if (op=='d') ny++;
            while (a[nx][ny]=='w'){
                nx=temx;
                ny=temy;
                char op;
                cin>>op;
                if (op=='r') break;
                if (op=='a') ny--;
                if (op=='w') nx--;
                if (op=='s') nx++;
                if (op=='d') ny++;
            }
            bflag++;
            if (bflag%5==0){
                    while (!q.empty()){
                    int xx=q.front().x;
                    int yy=q.front().y;
                    q.pop();
                    if (xx==-1){
                        q.push(node{-1,-1});
                        break;
                    }
                    for (int i=0;i<=3;i++){
                        int xn=xx+dx[i];
                        int yn=yy+dy[i];
                        if (xn>0&&xn<n+1&&yn>0&&yn<=n&&a[xn][yn]=='.'){
                            a[xn][yn]='x';
                            q.push(node{xn,yn});
                        }
                    }
                }

            }
        }
    }
    return 0;
}
