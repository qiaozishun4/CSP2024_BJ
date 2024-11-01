#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1000005],red,blue;
int cal(int p){
    red=0;
    blue=0;
    int s=0;
    red=num[0];
    for (int i=1;i<p;i++){
        if (num[i]==red){
            s+=red;
        }
        else if (num[i]==blue){
            s+=blue;
        }
        else{
            int ex_r=0,ex_b=0;//expectation
            for (int j=i+1;j<p;j++){
                if (num[j]==red){
                    ex_r=red;
                }
                else if (num[j]==blue){
                    ex_b=blue;
                }
                if (ex_r&&ex_b){
                    break;
                }
            }
            if (ex_r<ex_b){
                red=num[i];
            }
            else{
                blue=num[i];
            }
        }
    }
    return s;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int F;
    scanf("%d",&F);
    for (int x=0;x<F;x++){
        int n;
        scanf("%d",&n);
        for (int y=0;y<n;y++){
            scanf("%d",&num[y]);
        }
        printf("%d\n",cal(n));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
