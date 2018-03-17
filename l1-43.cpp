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
#include <cstdio>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int>maps;
	while (n--) {
		int people = 0, sum = 0, flag = 0;
		while (1) {
			char kind;
			int id, h, s;
			cin >> id >> kind;
			scanf("%d:%d", &h, &s);
			getchar();
			if (id == 0) break;
			if ( kind == 'S') {
				maps[id] = h * 60 + s;
			}
			else if (maps.count(id) && kind == 'E') {
				people ++ ;
				sum = sum + h * 60 + s - maps[id];
				flag = 1;
				map<int, int>::iterator it=maps.lower_bound(id);
				maps.erase(it);
			}

		}
		if (flag == 1){
			//cout << people << " " << (sum % people == 0 ? sum / people : round((double)sum/ people)) << endl;
			double ans=(double)sum/people;
			printf("%d %.0lf\n",people,ans);
		}
		else
			cout << "0 0" << endl;
		maps.clear();
	}

	return 0;
}

// #include"iostream"
// #include"cstdio"
// using namespace std;
// int main() {
// 	int n;
// 	cin >> n;
// 	int num, h, f, shu = 0;
// 	double sum = 0;
// 	char c;
// 	for (int i = 0; i < n; i++) {
// 		char a[1001];
// 		int start[1001] = {0};
// 		int end[1001] = {0};
// 		shu = 0;
// 		sum = 0;
// 		while (true) {
// 			scanf("%d %c %d:%d", &num, &c, &h, &f);
// 			if (num == 0) {
// 				break;
// 			}
// 			if (c == 'S') {
// 				a[num] = 'S';
// 				start[num] = h * 60 + f;
// 			}
// 			if (c == 'E' && a[num] == 'S') {
// 				end[num] = h * 60 + f;
// 				sum += end[num] - start[num];
// 				shu++;
// 				a[num] = '0';
// 			}
// 		}
// 		if (shu != 0) {
// 			if (sum == 0) {
// 				cout << shu << " " << 0 << endl;
// 			} else if (sum != 0) {
// 				cout << shu << " " << int((1.0 * sum / shu) + 0.5) << endl;
// 			}
// 		} else if (shu == 0) {
// 			cout << 0 << " " << 0 << endl;
// 		}
// 	}
// }