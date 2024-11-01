#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t,px=0,py=0,dr = 0,ans = 1;
bool v[1003][1003] = {0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans = 1;
        memset(v,0,sizeof(v));
        string maze[1003];
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&px,&py,&dr);
        py--;
        v[px][py] = 1;
        for(int i = 1;i<=n;i++){
            cin>>maze[i];
        }
        while(k--){
            //cout<<"ok";
            if(dr%4==0){
                if(0<=py+1 && m-1>=py+1 && 1<=px && n>=px && maze[px][py+1] == '.'){
                    py++;
                    if(v[px][py] == 0)ans++;
                    v[px][py] = 1;
                    //cout<<"go";
                    //cout<<px<<" "<<py<<endl;
                }
                else dr++;
            }
            else if(dr%4==1){
                if(0<=py && m-1>=py && 1<=px+1 && n>=px+1 && maze[px+1][py] == '.'){
                    px++;
                    if(v[px][py] == 0)ans++;
                    v[px][py] = 1;
                    //cout<<"go";
                    //cout<<px<<" "<<py<<endl;
                }
                else dr++;
            }
            else if(dr%4==2){
                if(0<=py-1 && m-1>=py-1 && 1<=px && n>=px && maze[px][py-1] == '.'){
                    py--;
                    if(v[px][py] == 0)ans++;
                    v[px][py] = 1;
                    //cout<<"go";
                    //cout<<px<<" "<<py<<endl;
                }
                else dr++;
            }
            else if(dr%4==3){
                if(1<=py && m>=py && 1<=px-1 && n>=px-1 && maze[px-1][py] == '.'){
                    px--;
                    if(v[px][py] == 0)ans++;
                    v[px][py] = 1;
                    //cout<<"go";
                    //cout<<px<<" "<<py<<endl;
                }
                else dr++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
