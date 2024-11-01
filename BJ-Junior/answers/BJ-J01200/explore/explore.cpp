#include<bits/stdc++.h>
using namespace std;
int f(int n,int m,int k,int x,int y,int d,string s){
    int cnt=0;
    bool mp[1005][1005];
    bool used[1005][1005];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            getline(cin,s);
            if(s[j]=='x') mp[i][j]=false;
            else mp[i][j]=true;
        }
    }
    for(int i=0;i<k;i++){
        switch(d){
            case 0:
                if(!mp[x][y++])
                    d=(d+1)%4;
                else
                    if(used[x][y++]) cnt++;
            case 1:
                if(!mp[x++][y])
                    d=(d+1)%4;
                else
                    if(used[x++][y]) cnt++;
            case 2:
                if(!mp[x][y--])
                    d=(d+1)%4;
                else
                    if(used[x][y--]) cnt++;
            case 3:
                if(!mp[x--][y])
                    d=(d+1)%4;
                else
                    if(used[x--][y]) cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    string s;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        a[i]=f(n,m,k,x-1,y-1,d,s);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<"\n";
    return 0;
}
