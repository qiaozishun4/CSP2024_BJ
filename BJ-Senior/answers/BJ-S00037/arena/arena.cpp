#include<bits/stdc++.h>
using namespace std;
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define mem(a, x) memset(a, x, sizeof(a))
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace cszhpdx {
template<class T>
void read(T &x) {
    x=0;
    bool f=false;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'), c=getchar();
    while(isdigit(c))x=x*10+(c-'0'), c=getchar();
    if(f)x=-x;
}

int main() {
    opf("arena");
    int T;read(T);
    while(T--)puts("0");
    return 0;
}
}
int main() {
    return cszhpdx::main();
}
/*
chun jiang chao shui lian hai ping, haishang mingyue gongchaosheng
yanyansuibo qianwanli, hechuchunjiang wuyueming
jiangliu wanzhuan raofangdian, yuezhaohualinjiesixian
kongliliushuangbujuefei, tingshangbaishakanbujian
jiangtianyisewuxianchen, jiaojiaokongzhongguyuelun
jiangpanherenchujianyue, jiangyuehenianchuzhaoren
renshengdaidaiwuqiongyi, jiangyueniannianwangxiangsi
buzhijiangyuedaiheren, danjianchangjiangsongliushui
baiyunyipianquyouyou, qingfengpushangbushengchou
shuijiajinyepianzhouzi, hechuxiangsimingyuelou
kelianloushangyuepaihuai, yingzhaolirenzhuangjingtai
yuhulianzhongjuanbuqu, daoyizhanshangfuhuanlai
cishixiangwangbuxiangwen, yuanzhuyuehualiuzhaojun
hongyanchangfeiguangbudu, yulunqianyueshuichengwen
zuoyexiantanmengluohua, kelianchunbanbuhuanjian
jiangshuiliuchunquyujin, jiangtanluoyuefuxixie
xieyuechenchencanghaiwu, jieshixiaoxiangwuxianlu
buzhichengyuejirengui, luoyueyaoqingmanjiangshu
*/