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
int flag1 = 0, flag2 = 0;
int fir[1005];

struct nod
{
	int lc, rc;
	nod(int a = 0, int b = 0): lc(a), rc(b) {};
};

vector<nod> vec;

int fun1(int l, int r) {
	int root = l;
	if (flag1 == 1) return 0;
	if (r < l)
		return 0;
	int i = l + 1;
	while (fir[i] < fir[root] && i <= r) i++;
	int p = i;
	while (fir[i] >= fir[root] && i <= r) i++;
	if (i != r + 1) flag1 = 1;
	vec[root].lc = fun1(l + 1, p - 1);
	vec[root].rc = fun1(p, r);
	return root;
}
int fun2(int l, int r) {

	int root = l;
	if (flag2 == 1) return 0;
	if (r < l)
		return 0;
	int i = l + 1;
	while (fir[i] >= fir[root] && i <= r) i++;
	int p = i;
	while (fir[i] < fir[root] && i <= r) i++;
	if (i != r + 1) flag2 = 1;
	vec[root].lc = fun2(l + 1, p - 1);
	vec[root].rc = fun2(p, r);
	return root;
}

void dfs(int root) {
	if (vec[root].lc != 0)dfs(vec[root].lc);
	if (vec[root].rc != 0)dfs(vec[root].rc);
	if(root != 0)
		cout << fir[root] << " ";
	else
		cout << fir[root] << endl;

}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fir[i];
		vec.push_back(nod());
	}
	int root = fun1(0, n - 1);
	if (!flag1) {
		cout << "YES" << endl;
		dfs(0);
	}
	else {
		int root = fun2(0, n - 1);
		if (!flag2) {
			cout << "YES" << endl;
			dfs(0);
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}