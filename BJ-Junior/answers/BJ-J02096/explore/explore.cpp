#include<iostream>
using namespace std;
int main(){
    int T,n,m,k,x,y,d,t=0;
    cin>>T;
    int num[T];
    for(int j=0;j<T;j++){
        num[j]=0;
    }
    while(t<T){
        cin>>n>>m>>k>>x>>y>>d;
        string a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                y+=1;
                if(y>m){
                    y-=1;
                    d=(d+1)%4;
                    break;
                }
            }
            else if(d==1){
                x+=1;
                if(x>n){
                    x-=1;
                    d=(d+1)%4;
                    break;
                }
            }
            else if(d==2){
                y-=1;
                if(y<0){
                    y+=1;
                    d=(d+1)%4;
                    break;
                }
            }
            else{
                x-=1;
                if(x<0){
                    x+=1;
                    d=(d+1)%4;
                    break;
                }
            }
            num[t]++;
        }
        t++;
    }
    for(int i=0;i<T;i++){
        cout<<num[i]<<endl;
    }
    return 0;
}