#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int totNumber;

#define MAXN 222
#define MAXM MAXN*33

struct trieNode {
	int number;
	trieNode* next[256];
} root[MAXM], *pbuf;

int insert(trieNode* p, const string& s) {
	for(int i=0,len=s.length(); i<len; ++i) {
		char c = s[i];
		if( p->next[c]==NULL ) {
			p->next[c] = ++pbuf;
		}
		p = p->next[c];
	}
	return p->number>0?p->number:p->number=++totNumber;
}

int map[MAXN][MAXN];

int main(int argc, char const *argv[]) {
	cin.sync_with_stdio(false);
	for(int n; cin>>n && ~n; ) {
		memset(root, 0x0, sizeof(root));
		pbuf = root;
		string a,b;
		cin >> a >> b;
		totNumber = 0;
		int s = insert(root, a);
		int t = insert(root, b);
		memset(map, 0x3f, sizeof(map));
		for(int i=0,w; i<n; ++i) {
			cin >> a >> b >> w;
			int x = insert(root, a);
			int y = insert(root, b);
			if ( w < map[x][y] ){
				map[x][y] = map[y][x] = w;
			}
		}
		static int dis[MAXN];
		static bool vis[MAXN];
		memset(vis, 0x0, sizeof(vis));
		memset(dis, 0x3f, sizeof(dis));
		std::queue<int> Q;
		vis[s] = true;
		dis[s] = 0;
		Q.push(s);
		while( !Q.empty() ) {
			int u = Q.front();
			vis[u] = false;
			Q.pop();
			for(int v=1; v<=totNumber; ++v) {
				if ( dis[v] > dis[u]+map[u][v] ) {
					dis[v] = dis[u]+map[u][v];
					if( !vis[v] ) {
						vis[v] = true;
						Q.push(v);
					}
				}
			}
		}
		cout << (dis[t]>=dis[0]?-1:dis[t]) << endl;
	}
	return 0;
}