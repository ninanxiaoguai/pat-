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

struct stuf
{
	double all, num;
	stuf(double a, double b): all(a), num(b) {}
};
int cmp(const stuf a, const stuf b) {
	return a.num / a.all > b.num / b.all;
}
double y[1010];

vector<stuf>vec;

int main() {
	double n, total;
	cin >> n >> total;
	for (int i = 0; i < n; i++)
		cin >> y[i];
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		vec.push_back(stuf(y[i], a));
	}
	sort(vec.begin(), vec.end(), cmp);
	vector<stuf>::iterator it;
	it = vec.begin();
	double le = total, sum = 0;
	while (1) {
		if ( it -> all < le) {
			//cout << it->all << " " << it->num << endl;
			sum = it->num + sum;
			le = le - it->all;
		}
		else {
			sum += (le * (it-> num)) / (it->all);
			break;
		}
		it++;

	}
	printf("%.2f\n", sum);
	return 0;
}