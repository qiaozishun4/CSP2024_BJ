/*
一场游戏分为若干回合。每回合,小 Q 会选择某只怪兽 i 以及另一只怪兽j(i ̸ = j),并让怪兽 i 向怪兽 j 发起攻击。此时,若怪兽 i 的攻击力小于等于怪兽 j 的防御力,则
无事发生;否则,怪兽 j 的防御被打破,怪兽 j 退出游戏不再参与到剩下的游戏中。一
只怪兽在整场游戏中 至多只能发起一次攻击。当未退出游戏的怪兽都已发起过攻击时,
游戏结束。小 Q 希望决定一组攻击顺序,使得在游戏结束时,未退出游戏的怪兽数量尽可能
少.
*/
#include<bits/stdc++.h>
using namespace std;
int n,maxn,t,cnt,a[100050];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]<maxn){
            t=a[i];
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==t) cnt++;
    }
    cout<<cnt;
    return 0;
}
