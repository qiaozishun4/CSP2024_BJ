#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+5;

int n;
int r[N];
int ans;

struct monster{
    int num,r;
    bool operator < (const monster& a) const {
        if(r != a.r) return r < a.r;
        else return num > a.num;
    }
    bool operator > (const monster& a) const {
        if(r != a.r) return r > a.r;
        else return num < a.num;
    }
};
priority_queue<monster, vector<monster>, greater<monster> > atk;    //the smaller r is in the front, if r=r the bigger num is in the front
bool alive[N];   //is it alive?

int cnt = 1;
pair<int,int> m[N];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans = n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&r[i]);
        m[i].first = i;
        m[i].second = r[i];
        atk.push(monster{i,r[i]});
        alive[i] = 1;
    }
    sort(m+1,m+n+1,cmp);
    while(atk.size()){
        monster now = atk.top();
        atk.pop();
        if(!alive[now.num]) continue;
        if(now.num == m[cnt].first) continue;
        if(now.r <= m[cnt].second) continue;    //cannot attack
        alive[m[cnt].first] = 0;
        ans--;
        cnt++;
    }
    printf("%d\n",ans);
    return 0;
}
