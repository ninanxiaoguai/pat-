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
int aa[10000], peo[10000], are[10000], hous[10000];
set<int> sets;
set<int> setes;
vector<int>vec;

int fun(int e) {return aa[e] == e ? e : aa[e] = fun(aa[e]);}

void mak(int a, int b) {
	if (fun(a) != fun(b)) {
		int pa = fun(a), pb = fun(b);
		aa[pa] = pb;
		peo[pb] = peo[pb] + peo[pa];
		hous[pb] = hous[pb] + hous[pa];
		are[pb] = are[pb] + are[pa];
	}
}

int cmp(const int &a, const int &b) {
	if ((double)are[fun(a)] / peo[fun(a)] == (double)are[fun(b)] / peo[fun(b)])
		return a < b;
	else
		return (double)are[fun(a)] / peo[fun(a)] > (double)are[fun(b)] / peo[fun(b)];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10000; i++) {
		aa[i] = i;
		are[i] = 0;
		hous[i] = 0;
		peo[i] = 1;
	}
	while (n--) {
		int a, f, m, g, t, area;
		cin >> a >> f >> m >> g;
		sets.insert(a);
		if (f != -1) {mak(a, f); sets.insert(f);}
		if (m != -1) {mak(a, m); sets.insert(m);}
		while (g--) {
			int v;
			cin >> v;
			sets.insert(v);
			mak(a, v);
		}
		int w, bb;
		cin >> w >> bb;
		hous[fun(a)] += w;
		are[fun(a)] += bb;
	}
	for (int i = 0; i < 10000; i++) {
		if (sets.count(i) && aa[i] == i)
			setes.insert(i);
	}
	for (int i = 0; i < 10000; i++) {
		if (setes.count(fun(aa[i]))) {
			vec.push_back(i);
			setes.erase(setes.lower_bound(aa[i]));
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	vector<int>::iterator it;
	cout << vec.size()<<endl;
	for(it = vec.begin();it != vec.end();it++){
		printf("%04d %d %.3f %.3f\n", *it ,peo[fun(*it)],
			(double)hous[fun(*it)]/peo[fun(*it)],
			(double)are[fun(*it)] / peo[fun(*it)]);
	}
	return 0;
}

