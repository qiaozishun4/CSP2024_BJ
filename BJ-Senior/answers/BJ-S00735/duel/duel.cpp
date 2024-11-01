#include <bits/stdc++.h>
using namespace std;
int n,ans;
queue<int> M;
int card[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    ans=n;
    sort(card,card+n);
    int flag=0;
    for(int i=0;i<n;i++){
        if(card[i]!=card[i-1]&&i>0){
            M.push(flag);
            flag=1;
        }
        else if(i==0){
            flag++;
        }
        else if(card[i]==card[i-1]){
            flag++;
        }

        if(M.size()==2){
            int a;
            a=M.front();
            M.pop();
            if(M.front()>=a){
                ans=ans-a;
            }
            else if(M.front()<a){
                ans=ans-M.front();
                M.front()=M.front()+(a-M.front());
            }
        }

        if(i==(n-1)){
            M.push(flag);
            if(M.size()==2){
                int a;
                a=M.front();
                M.pop();
                if(M.front()>=a){
                    ans=ans-a;
                }
                else if(M.front()<a){
                    ans=ans-M.front();
                    M.front()=M.front()+(a-M.front());
                }
            }
        }
    }
    cout<<ans;
    return 0;
}