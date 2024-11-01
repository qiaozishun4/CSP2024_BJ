#include <algorithm>
#include <cstdio>
#define PROB "duel"
namespace FIO{
	const size_t IBufSz = 1048576;
	const size_t OBufSz = 1048576;
	char ibuf[IBufSz],obuf[OBufSz];
	char *ipk,*ied,*opk;
	FILE *inf,*ouf;
	inline void Open(const char *i,const char *o){
		inf = fopen(i,"rb"),ouf = fopen(o,"wb");
		ipk = ied = ibuf,opk = obuf;
	}
	inline void Open(FILE *i,FILE *o){
		inf = i,ouf = o,ipk = ied = ibuf,opk = obuf;
	}
	inline char GetChar(){
		if(ipk == ied)
			ied = (ipk = ibuf) + fread(ibuf,1,IBufSz,inf);
		return ipk == ied?EOF:*(ipk ++);
	}
	inline void Flush(){
		fwrite(obuf,1,opk - obuf,ouf),opk = obuf;
	}
	inline void Close(){
		Flush(),fclose(inf),fclose(ouf);
	}
	struct __IOGuard{~__IOGuard(){Close();}} __IOG;
	inline void PutChar(char c){
		if(opk == obuf + OBufSz) Flush();
		*(opk ++) = c;
	}
	template<typename T>
	inline T ReadInt(){
		char ch = GetChar();
		T res = 0;
		bool sgn;
		do{
			sgn = false;
			while((ch < '0' || '9' < ch) && ch != '-')
				ch = GetChar();
			if(ch == '-') sgn = true,ch = GetChar();
		}while(ch < '0' || '9' < ch);
		while('0' <= ch && ch <= '9'){
			res = (res << 3) + (res << 1) + (ch ^ 48);
			ch = GetChar();
		}
		return sgn?-res:res;
	}
	template<typename T>
	inline void WriteInt(T x){
		if(x < 0)
			return PutChar('-'),WriteInt(-x),void();
		if(x > 9) WriteInt(x / 10);
		PutChar('0' + x % 10);
	}
	inline char ReadChar(){
		char ch = GetChar();
		while(ch == ' ' || ch == '\r' || ch == '\n' || 
				ch == '\t' || ch == '\v')
			ch = GetChar();
		return ch;
	}
}
int r[100010],q[100010];
int main(){
#ifdef DBG
	FIO::Open(stdin,stdout);
#else
	FIO::Open(PROB ".in",PROB ".out");
#endif
	int n = FIO::ReadInt<int>();
	int qh = 1,qt = 0;
	for(int i = 1;i <= n;i ++)
		r[i] = FIO::ReadInt<int>();
	std::sort(r + 1,r + n + 1);
	for(int i = 1;i <= n;i ++){
		if(qh <= qt && q[qh] < r[i])
			qh ++;
		q[++qt] = r[i];
	}
	FIO::WriteInt(qt - qh + 1);
	return 0;
}