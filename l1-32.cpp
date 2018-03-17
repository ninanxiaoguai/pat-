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

int f[105][105], s[105][105], ans[105][105];


int main () {
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	memset(s, 0, sizeof(ans));
	int a1, a2, b1, b2;
	cin >> a1 >> a2;
	for (int i = 0; i < a1; i++)
		for (int j = 0; j < a2; j++)
			cin >> f[i][j];
	cin >> b1 >> b2;
	if (a2 != b1) {
		cout << "Error: " << a2 << " != " << b1 << endl;
	}
	else {
		for (int i = 0; i < b1; i++)
			for (int j = 0; j < b2; j++)
				cin >> s[i][j];

		for (int i = 0; i < a1; i++) 
			for (int j = 0; j < b2; j++) 
				for (int m = 0; m < a2; m ++) 
						ans[i][j] += f[i][m] * s[m][j];
		cout << a1 << " " <<b2<<endl;
		for (int i = 0; i < a1; i++) {
			int first = 1;
			for (int j = 0; j < b2; j++)
				if (first == 1) {
					first ++;
					cout << ans[i][j];
				}
				else
					cout << " " << ans[i][j];
			first = 1;
			cout << endl;
		}
	}
	return 0;
}