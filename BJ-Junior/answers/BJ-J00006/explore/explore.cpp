#include<iostream>
#include<cstdio>
using namespace std;
int t;
int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
struct se{
    int n,m,k,x0,y0,d0,cnt=0;
    char c[1001][1001];
    void in(){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=0;i<n;i++)cin>>c[i];
    }
    int dfs(int x,int y,int d){
        if(cnt>k)return 0;
        else if(cnt==k) return 1;
        if(c[x+xx[d]][y+yy[d]]=='.'){cnt+=1;return dfs(x+xx[d],y+yy[d],d)+1;}
        else{
            while(c[x+xx[d]][y+yy[d]]!='.'){
                d=(d+1)%4;cnt+=1;
                if(cnt>k)return 0;
            }cnt+=1;
            if(cnt>k)return 0;
            else if(cnt==k)return 1;
            return dfs(x+xx[d],y+yy[d],d)+1;
        }
    }
}s[6];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        s[i].in();
        cout<<s[i].dfs(s[i].x0,s[i].y0,s[i].d0)+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}