#include<bits/stdc++.h>
using namespace std;
bool he[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    char a[1005][1005];
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int xa,ya,d;
        scanf("%d%d%d",&xa,&ya,&d);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=999;i++){
            for(int j=0;j<=999;j++){
                he[i][j]=false;
            }
        }
        xa--;
        ya--;
        he[xa][ya]=true;
        int sum=0;
        while(k--){
            switch(d){
                case 0:{
                    if(ya+1>=m||a[xa][ya+1]=='x') {
                        d++;
                        d%=4;
                        break;
                    }
                    ya++;
                    he[xa][ya]=true;
                }break;
                case 1:{
                    if(xa+1>=n||a[xa+1][ya]=='x'){
                        d++;
                        d%=4;
                        break;
                    }
                    xa++;
                    he[xa][ya]=true;
                }break;
                case 2:{
                    if(ya-1==-1||a[xa][ya-1]=='x'){
                        d++;
                        d%=4;
                        break;
                    }
                    ya--;
                    he[xa][ya]=true;
                }break;
                case 3:{
                    if(xa-1==-1||a[xa-1][ya]=='x'){
                        d++;
                        d%=4;
                        break;
                    }
                    xa--;
                    he[xa][ya]=true;
                }break;
            }
            he[xa][ya]==true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(he[i][j])sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

