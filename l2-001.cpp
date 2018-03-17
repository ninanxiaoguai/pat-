#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <memory>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

int n, m, s, d, ma = 50000;
int g[505][505], w[505], dd[505], peo[505], path[510], vis[510], ways[510];

void fun(int i) {
	for (int j = 0; j < n; j++)
		if (g[i][j] != -1){
			if (dd[j] > dd[i] + g[i][j]) {
				ways[j]=ways[i];
				dd[j] = dd[i] + g[i][j];
				peo[j] = peo[i] + w[j];
				path[j] = i;
			}
			else if(dd[j] == dd[i] + g[i][j]){
				ways[j]+=ways[i];
				if(peo[j]<peo[i]+w[i]){
					peo[j] = peo[i] + w[j];
				    path[j] = i;
				}
			}
		}

}

int shor() {
	int k = 50000000, id;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		if (dd[i] < k){
			id = i;
			k = dd[i];
		}
	}

	return id;
}

void pa(int e) {
	if (e == s) {
		cout << e;
		return;
	}

	pa(path[e]);
	cout << " " << e;
}


int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(g, -1, sizeof(g));
	cin >> n >> m >> s >> d;


	for (int i = 0 ; i < n; i++)
		cin >> w[i];
	for (int i = 0 ; i < m; i++) {
		int a , b , c;
		cin >> a >> b >> c;

		if(g[a][b]==-1||g[a][b]> c) g[a][b]=g[b][a]=c;

	}

	memset(vis, 0, sizeof(vis));
	for (int i = 0 ; i < n; i++)
		dd[i] = 999999999;
	dd[s] = 0;
	peo[s] = w[s];
	ways[s] = 1;
	int x;


	while (1) {
		x = shor();
		vis[x] = 1;
		if (x == d) break;
		fun(x);
	}
	cout << ways[d] << ' ' << peo[d] << endl;
	pa(d);
	cout << endl;
	return 0;
}