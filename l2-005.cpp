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
set<int> sets[55];
int d[55][55];

void fun(int i, int j) {
	if (d[i][j] != -1){
		//cout<<i<<' '<<j<<endl;
		printf("%.2f%\n", d[i][j]*0.01);
	}
		else {
			double ncn = 0, ntn = 0;
			set<int>nc;
			set<int>:: iterator it;
			for (it = sets[i].begin(); it != sets[i].end(); it++) {
				nc.insert(*it);
			}
			for (it = sets[j].begin(); it != sets[j].end(); it++) {
				if (nc.count(*it))
					ncn ++ ;
				else
					nc.insert(*it);
			}
			ntn = nc.size();
			printf("%.2f%\n", ncn / ntn * 100);
			d[j][i] = d[i][j] = ncn / ntn * 10000;
		}

}

int main() {
	int nn;
	cin >> nn;
	memset(d,-1,sizeof(d));
	for (int i = 0; i < nn; i ++) {
		int k;
		cin >> k;
		while (k--) {
			int p;
			scanf("%d", &p);
			sets[i].insert(p);
		}
	}
	int g, m, n;
	cin >> g;
	while (g--) {
		scanf("%d %d", &m, &n);
		fun(m - 1, n - 1);
	}

	return 0;
}