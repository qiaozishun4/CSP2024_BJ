#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=1000000;++i){
            int I=i,chk=0;
            while(I>9){
                chk+=a[I%10];
                I/=10;
            }
            chk+=a[I];
            if(chk==n){
                ans=i;
                break;
            }
        }
        if(ans)cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}










/*
                2022/09/01 —— 2024/10/26
告别赛，就应该特别一点。

呵呵，没人会看见的 对吧。。？
我的OI生涯，到此结束了。也许在你看来很可惜吧。。？
但是，我依旧觉得：竞赛的水很深，深到发浅。
希望那之后，我不后悔。到时候，我希望你我还能是最好的朋友，就像我们初次见面时，一样。

                                            ————于北京市第八十中学望京校区
另：下附《醉翁亭记》一篇，欧阳修写的不错。
*/
/*
        醉翁亭记 北宋 欧阳修
    环滁皆山也。其西南诸峰，林壑尤美，望之蔚然而深秀者，琅琊也。山行六七里，渐闻水声潺潺，而泻出于两峰之间者，酿泉也。
峰回路转，有亭翼然临于泉上者，醉翁亭也。作亭者谁？山之僧智仙也。名之者谁？太守自谓也。太守与客来饮于此，饮少辄醉，而年
又最高，故自号曰醉翁也。醉翁之意不在酒，在乎山水之间也。山水之乐，得之心而喻之酒也。
    若夫日出而林扉开，云归而岩穴暝，晦明变化者，山间之朝暮也。野芳发而幽香，佳木秀而繁阴，风霜高洁，水落而石出者，山间
之四时也。朝而往，暮而归，四时之景不同，而乐亦无穷也。
    至于负者歌于途，行者休于树，伛偻提携，往来而不绝者，滁人游也。临溪而渔，溪深而鱼肥，酿泉为酒，泉香而酒冽，山肴野
蔌，杂然而前陈者，太守宴也。宴酣之乐，非丝非竹，射者中，弈者胜，觥筹交错，起坐而喧哗者，众宾欢也。苍颜白发，颓然乎其间
者，太守醉也。
    已而夕阳在山，人影散乱，太守归而宾客从也。树林阴翳，鸣声上下，游人去而禽鸟乐也。然而禽鸟知山林之乐，而不知人之乐；
人知从太守游而乐，而不知太守之乐其乐也。醉能同其乐，醒能述以文者，太守也。太守谓谁？庐陵欧阳修也。
*/
