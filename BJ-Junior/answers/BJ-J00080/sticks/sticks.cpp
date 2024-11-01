#include<bits/stdc++.h>
using namespace std;

int t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
string b[7]={"888","108","188","200","208","288","688"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    scanf("%d",&t);
    for(int p=1;p<=t;p++){
        scanf("%d",&n);
        if(n<=1){
            printf("%d\n",-1);
        }
        else if(n<=7){
            int ans=-1;
            for(int i=1;i<=9;i++){
                if(a[i]==n){
                    ans=i;
                    break;
                }
            }
            printf("%d\n",ans);
        }
        else if(n<=14){
            int ans=-1;
            for(int i=1;i<=9;i++){
                for(int j=0;j<=9;j++){
                    if(a[i]+a[j]==n){
                        ans=i*10+j;
                        break;
                    }
                }
                if(ans!=-1) break;
            }
            printf("%d\n",ans);
        }
        else{
            cout<<b[n%7];
            for(int i=1;i<=(n-1)/7-2;i++){
                printf("8");
            }
            printf("\n");
        }

    }

    return 0;
}
