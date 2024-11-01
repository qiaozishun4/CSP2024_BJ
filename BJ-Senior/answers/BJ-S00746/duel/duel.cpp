#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[100005];
int flag;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum=n/3;
    if(n%3){
        sum++;
    }
    for(int i=1;i<sum;++i){
        if(i==sum){
            if(n%3==1){
                if(a[n]>a[n-1]){
                    cnt++;
                }
                break;
            }else if(n%3==2){
                if(a[n]>a[n-1]){
                    cnt++;
                }
                break;
            }
        }
        int x=3*i+1;
        int y=3*i+2;
        int z=3*i+3;
        if(a[x]==a[y]&&a[y]!=a[z]){
            cnt++;
            if(flag==2&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==1&&a[x]==a[x-1]){
                cnt++;
            }
            if(flag==1&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==3&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==4&&a[x]>a[x-1]){
                cnt++;
            }
            flag=1;//1+1+2
        }else if(a[x]!=a[y]&&a[y]==a[z]){
            cnt++;
            if(flag==1){
                cnt+=2;
            }
            if(flag==2&&a[x]==a[x-1]){
                cnt++;
            }
            if(flag==2&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==3&&a[x]==a[x-1]){
                cnt++;
            }
            if(flag==3&&a[x]>a[x-1]){
                cnt+=2;
            }
        }else if(a[x]==a[y]&&a[y]==a[z]){
            if(flag==1&&a[x]==a[x-1]){
                cnt++;
            }
            if(flag==1&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==2&&a[x]>a[x-1]){
                cnt+=2;
            }
            if(flag==3&&a[x]>a[x-1]){
                cnt+=3;
            }
            if(flag==4&&a[x]>a[x-1]){
                cnt++;
            }
        }else if(a[x]!=a[y]&&a[y]!=a[z]){
            if(a[x+3]>a[x]){
                cnt++;
            }
            if(a[y+3]>a[y]){
                cnt++;
            }
            if(a[z+3]>a[z]){
                cnt++;
            }
        }
    }
    cout<<n-cnt;
   return 0;
}
