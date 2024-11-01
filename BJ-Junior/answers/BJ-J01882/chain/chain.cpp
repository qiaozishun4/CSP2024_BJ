#include <bits/stdc++.h>
// long long freopen
using namespace std;
int const N = 1e3 + 10;
int n, m, k, x, y, d, t[N][N];

void Main() {
    stack <int> t;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    int k = n / 7;
    while (k--) t.push(8);
    k = n / 7;
    int s = n % 7;
    if (s == 0) {
        while (!t.empty()) {
            cout << t.top();
            t.pop();
        }
        cout << endl;
        return;
    }
    if (s + k >= 2 && s <= 2) {
        k = 2 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(1);
    }
    else if (s + k >= 5 && s <= 5) {
        k = 5 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(2);
    }
    else if (s + k >= 4 && s <= 4) {
        k = 4 - s;
        for (int i = 1;i <= k;++i) t.pop();
        for (int i = 1;i <= k;++i) t.push(0);
        t.push(4);
    }

    else if (s == 1 && k == 0) {
        t.pop();
        t.push(6);
        t.push(1);
    }
    else if (s == 2) t.push(1);
    else if (s == 3) t.push(7);
    else if (s == 4) t.push(4);
    else if (s == 5) t.push(2);
    else if (s == 6) t.push(6);
    while (!t.empty()) {
        cout << t.top();
        t.pop();
    }
    cout << endl;
}

int main() {
    freopen("sticks.in","r", stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while (T--) Main();
    return 0;
}


// xian zai shi 9:36, yi jing zuo wan t3 le
// t1 t2 quan shi mo ni sui bian xie dou neng guo
// hai du cuo ti le xia tiao le hao jiu
// t3 jiu shi yi ge da tan xin, hen jian dan
// dan shi wei shen mo cc f zhi gei le yi ge yang li
// wo jue de ke neng hui wa a
// zhe chang cs p hao jian dan
// xi wang xia wu chang ye zhe yang
// xian zai kan t4

//t4 sha dong xi a, zhe shi pu ji zu gai chu xian de ti ma
//wo jue de dou you sheng xuan nan du le
//xiang le hen jiu ying gai shi yi ge DP
//she dp(i,j,r) biao shi yi di i ge ren, di j ge shu, di r lun jie wei shi fou ke neng
//yu shi you dp(i,j,r) = max(dp(l(l bu deng yu i),S_i,j = S_l,j-k, r-1)) dan shi zhe yang jiu shi O(n^2mkr)
// hen ming xian hui tle
// kao lv shi yong shu tao shu lai you hua, ke yi ba zhuan yi fu za du xia jiang dao O(log n log k)
// dan shi zhe yang hai you dian ka chang
// er qie zhe ge ti hai qiang po yong stl chang shu geng da le
// er qie han nan xie wo jue de wo tiao dao jie shu dou tiao bu wan
// xiang kai bai le, fan zheng 300pts 1= chuo chuo you yu
// ji shi gua yi dian ye mei guan xi
// t4 ye ke neng you ge tu lun zuo fa
// dan shi hua le hao jiu ye mei tui chu ge sha le
// hai shi tai cai le

// xian zai hai you 40 min jiu jie shu le
// kai bai, bu xie t4 le
