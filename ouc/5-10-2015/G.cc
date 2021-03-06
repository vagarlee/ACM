#include <cstdio>
#define MAX_LEN 11111111

int  mon[13] = {0,31,60,91,121,152,182,213,244,274,305,335,366};
int  n, m, head, tail;
int  queue[MAX_LEN];
char s[MAX_LEN];

int main(int argc, char const *argv[])
{
	scanf("%d%d\n", &n, &m);
	int month, days, hour, minute, second, current;
	while(scanf("2012-%d-%d %d:%d:%d: ", &month, &days, &hour, &minute, &second)!=EOF){
		current = (mon[month-1]+(days-1))*86400+hour*3600+minute*60+second;
		queue[tail++] = current;
		for(;head<tail && queue[head] <= current-n; ++head);
		if(tail-head >= m){
			printf("2012-%02d-%02d %02d:%02d:%02d\n", month, days, hour, minute, second);
			return 0;
		}
		gets(s);
	}
	printf("-1\n");
	return 0;
}
