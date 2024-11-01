#include<bits/stdc++.h>
using namespace std;
int movement(int a,int b,int k,int x,int y,int d){
    int m[a+1][b+1],touch[a+1][b+1]={};
    char c;
    int rp,score;
    for(rp=1;rp<=a;rp++)
    {
        for(score=1;score<=b;score++)
        {
            cin>>c;
            if(c=='x')
                m[rp][score]=1;
            else
                m[rp][score]=0;
        }
    }
    k++;
    while(k--)
    {
        touch[x][y]=1;
        if(d==0)
        {
            if(y==b)
            {
                d=1;
                continue;
            }
            if(m[x][y+1]==1)
            {
                d=1;
                continue;
            }
            y++;
        }
        if(d==1)
        {
            if(x==a)
            {
                d=2;
                continue;
            }
            if(m[x+1][y]==1)
            {
                d=2;
                continue;
            }
            x++;
        }
        if(d==2)
        {
            if(y==1)
            {
                d=3;
                continue;
            }
            if(m[x][y-1]==1)
            {
                d=3;
                continue;
            }
            y--;
        }
        if(d==3)
        {
            if(x==1)
            {
                d=0;
                continue;
            }
            if(m[x-1][y]==1)
            {
                d=0;
                continue;
            }
            x--;
        }
    }
    k=0;
    for(x=1;x<=a;x++)
    {
        for(y=1;y<=b;y++)
        {
            if(touch[x][y]==1)
                k++;
        }
    }
    return k;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int i,n,t;
    int m,x,y,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>i;
        cout<<movement(n,m,k,x,y,i)<<endl;
    }
    return 0;
}