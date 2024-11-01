#include<iostream>
#include<cstdio>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
void f(int n,int y){
    for(int i=0;i<10;i++){
        if(n-a[i]>0&&y!=0){
            y*=10;
            y+=i+1;
            n-=a[i];
        }
        if(y==0&&n-a[i]>0){
            if(i!=0){
                y*=10;
                y+=i+1;
                n-=a[i];
            }
        }
        return f(n,y);
        if(n==1){
            cout<<-1<<endl;
        }
        if(n==0){
            cout<<y<<endl;

        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int o;
    cin>>o;
    for(int i=0;i<o;i++){
        int n;
        cin>>n;
        f(n,0);
        }

    fclose(stdin);
    fclose(stdout);
    return 0;
    }
