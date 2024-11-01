#include<iostream>
#include<fstream>
#include<string>
using std::endl,std::string,std::ifstream;
ifstream cin("explore.in");
ofstream cout("explore.out");

bool map[1105][1105];
bool rendered[1105][1105];
size_t cx,cy,t,ans;
class point
{
public:
    int x=0,y=0;
    inline point(){}
    inline point(int _x,int _y):x(_x),y(_y){}
    inline point operator+(point other){return {x+other.x,y+other.y};}
    inline point& operator+=(point other){return *this=*this+other;}
    inline point operator-(point other){return {x-other.x,y-other.y};}
    inline point& operator-=(point other){return *this=*this-other;}
};
void go(point& pos,int& direct)
{
    static const point vec[]{{0,1},{1,0},{0,-1},{-1,0}};
    //print(pos,direct);
    point pt=pos+vec[direct&=0x3];
    if((size_t)pt.x<cx&&(size_t)pt.y<cy&&map[pt.x][pt.y])
        pos=pt;
    else direct+=1;
    if(!rendered[pos.x][pos.y])
        rendered[pos.x][pos.y]=true,
        ans++;
}
void run()
{
    cin>>cx>>cy>>t;
    point p;int direct;
    cin>>p.x>>p.y>>direct;
    p-={1,1};
    ans=1;
    for(size_t i=0;i<cx;i++)
        for(size_t j=0;j<cy;j++)
    {
        char c;cin>>c;
        map[i][j]=c=='.';
        rendered[i][j]=0;
    }
    rendered[p.x][p.y]=true;
    while(t--)go(p,direct);
    //print(p,direct);
    cout<<ans<<endl;
}
int main()
{
    int term;cin>>term;
    while(term--)run();
    return 0;
}
