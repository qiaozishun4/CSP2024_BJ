#include<iostream>
using namespace std;
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
int b[10];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int a;
    cin>>a;
    for(int k=1;k<=a;k++){
        b[k]=1;
        int c,d,e,f,g,h;
        cin>>c>>d>>e;
        cin>>f>>g>>h;
        char z[c+1][d+1];
        int u[c+1][d+1];
        for(int i=1;i<=c;i++){
            for(int j=1;j<=d;j++){
                cin>>z[i][j];
                u[i][j]=0;
            }
        }
        u[f][g]=1;
        while(e!=0){
            if(f+x[h]<=c&&f+x[h]>=1&&g+y[h]<=d&&g+y[h]>=1&&z[f+x[h]][g+y[h]]!='x'){
				f=f+x[h];
                g=g+y[h];
				if(u[f][g]==0){
					b[k]++;
				}
				u[f][g]=1;
            }else{
                h=(h+1)%4;
            }
            e--;
        }
    }
    for(int i=1;i<=a;i++){
        cout<<b[i]<<endl;
    }
    return 0;
}
