#include <bits/stdc++.h>
using namespace std;
struct num{
    int number;
    int countt;
};
num a[10] = {{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
int t,n,b;
int weishu;
int ans[15000],k;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 1){
            cout<<-1<<endl;
            continue;
        }
        weishu = n / 7;
        if(n%7 != 0)weishu++;
        if(weishu == 1){
            for(int i = 1;i<9;i++){
                if(a[i].countt == n){
                    cout<<a[i].number<<endl;
                    break;
                }
            }
        }else{
            k = 0;
            b = n - (weishu-1)*7;
            for(int i = 1;i<9;i++){
                if(a[i].countt >= b){
                    ans[k++] = a[i].number;
                    n -= a[i].countt;
                    break;
                }
            }
            weishu--;
            while(weishu){
                if(weishu == 1){
                    for(int i = 0;i<9;i++){
                        if(a[i].countt == n){
                            ans[k++] = a[i].number;
                            break;
                        }
                    }
                }else{
                    b = n-(weishu-1)*7;
                    for(int i = 0;i<9;i++){
                        if(a[i].countt >= b){
                            ans[k++] = a[i].number;
                            n -= a[i].countt;
                            break;
                        }
                    }
                }
                weishu--;
            }
            for(int i = 0;i<k;i++){
                printf("%d",ans[i]);
            }
            cout<<endl;
        }
    }
	return 0;
}
