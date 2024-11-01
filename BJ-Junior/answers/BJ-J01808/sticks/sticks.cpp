#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    int n;
    int s[13]={6,2,5,5,4,5,6,3,7,6};
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n>=0&&n<=9){
            int flag=-1;
            for(int i=1;i<=9;i++){
                if(s[i]==n){
                    cout<<i<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==-1){
                cout<<flag<<endl;
            }
        }else{
            int flag=-1;
            int sum;
            for(int i=1;i<=30000;i++){
                int f=i;
                sum=0;
                while(f){
                    sum+=s[f%10];
                    f/=10;
                }
                if(sum==n){
                    flag=1;
                    cout<<i<<endl;
                    break;
                }
            }
            if(flag==-1){
                cout<<flag<<endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
