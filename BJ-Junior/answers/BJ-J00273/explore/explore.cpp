#include<iostream>
#include<cstdio>
using namespace std;

int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    int v[4]={0,-1,0,1};
    int v1[4]={1,0,-1,0};
    for(int c=0;c<n;c++){
        long long n,m,k;
        cin>>n>>m>>k;
        char a[n+10][m+10];
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cin>>a[i][j];
            }
        }
        x-=1;y-=1;
        int u=0;
        while(k>=0){
        k--;
        if(a[x+v[d%4]][y+v[d%4]]!='x'&&((x+v[d%4]>=0)&&(x+v[d%4])<n)&&((y+v1[d%4]>=0)&&(y+v1[d]%4)<m)){
            x+=v[d];
            y+=v1[d];
            u++;
        }
        else{
            d++;

        }
        }
       cout<<u+1<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
