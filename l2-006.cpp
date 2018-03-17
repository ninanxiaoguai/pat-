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

int hou[500], zhong[500], lc[500], rc[500];
queue<int> que;

int fun(int h1, int h2, int z1, int z2 ) {
	
	int root = hou[h2];
	if (h1 > h2) return -1;
	int p = z1;
	while (hou[h2] != zhong[p]) p ++;
	int nn = p - z1;
	lc[root] = fun(h1, h1 + nn - 1, z1, z1 + nn - 1);
	rc[root] = fun(h1 + nn, h2 - 1, p + 1, z2);
	//cout << lc[root] <<" " << hou[root] <<" " << rc[root] <<" "<<endl;
	return root;
}


int main() {
	memset(lc,-1,sizeof(lc));
	memset(rc,-1,sizeof(rc));
	int n,first = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> hou[i];
	for (int i = 0; i < n; i++)
		cin >> zhong[i];
	int root = fun(0, n - 1, 0, n - 1);
	que.push(root);
	while (!que.empty()) {
		int k = que.front();
		que.pop();
		if(first == 1){
			cout << k ;
			first++;
		}
		else{
			cout << " " <<k;
		}
		if(lc[k] != -1) que.push(lc[k]);
		if(rc[k] != -1) que.push(rc[k]);
	}
	cout << endl;

	return 0;
}