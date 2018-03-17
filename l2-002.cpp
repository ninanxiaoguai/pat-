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

vector<int> v1;
vector<int> v2;
int nex[1000000];
int val[1000000];
set<int>sets;

int main() {
	int first, n;
	cin >> first >> n;
	int nn = n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		nex[a] = c;
		val[a] = b;
	}
	int value, p = first;
	while (p != -1) {
		value = val[p];
		if (sets.count(abs(value)))
			v2.push_back(p);
		else {
			sets.insert(abs(value));
			v1.push_back(p);
			//cout << val[p];
		}
		p = nex[p];
	}

	vector<int>::iterator it;
	for (it = v1.begin(); it + 1 != v1.end(); it++) {
		int tem = *it;
		printf("%05d %d %05d\n", tem, val[tem], *(it + 1) );
	}
	it = v1.end() - 1;
	int y = *it;
	printf("%05d %d %d\n", y, val[y], -1 );
	if (v2.size() != 0) {
		for (it = v2.begin(); it + 1 != v2.end(); it++) {
			int tem = *it;
			printf("%05d %d %05d\n", tem, val[tem], *(it + 1) );
		}
		it = v2.end() - 1;
		y = *it;
		printf("%05d %d %d\n", y, val[y], -1 );
	}
	return 0;
}