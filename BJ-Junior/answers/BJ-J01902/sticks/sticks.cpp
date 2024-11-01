#include<iostream>
using namespace std;
char num[10]={'0','1','2','4','6','7','8'};
int much[10]={ 6,  2,  5,  4,  6,  3,  7 };
int cnt,n;
string ans;
bool flag=0;
void dfs(int k,int yu){
    if(flag==true)return;
    if(k>cnt){
        if(yu==0){
            cout << ans << endl;
            flag=true;
            return;
        }
        else{
            ans="";
            return;
        }
    }
    for(int i=0;i<=5;i++){
        if(flag)return;
        if(k==1&&i==0){
            ans+='6';
            dfs(k+1,yu-6);

        }
        else{
            ans+=num[i];
            dfs(k+1,yu-much[i]);

        }
    }
    return;
}
int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cnt=0;
        flag=0;
        ans="";
        cin >> n;

        if(n==1||n==8||n==9)
        {
            cout << -1;
            cout << endl;
            continue;
        }
        if(n%7==0)
        {
            cnt=n/7;
            for(int i=1;i<=cnt;i++)
            {
                cout << '8';
            }
            cout << endl;
            continue;
        }

        if(n%7==1)
        {
            cout << '1' << '0';
            cnt=n/7;
            for(int i=1;i<=cnt;i++)
            {
                cout <<'8';
            }
            cout <<endl;
            continue;
        }

        cnt=(n+6)/7;
        dfs(1,n);
    }
    return 0;
}
