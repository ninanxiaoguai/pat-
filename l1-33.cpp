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

map<int,int>maps;
vector<pair<int,int>> vec;

int cmp(const pair<int,int> &x,const pair<int,int> &y){
	if(x.second == y.second)
		return x.first > y.first;
	else
		return x.second > y.second;
}

int main() {
	int n;
	cin >> n;
	while(n--){
		int r;
		cin >> r;
		while(r--){
			int name;
			cin >> name;
			if(!maps.count(name))
				maps[name] = 1;
			else maps[name]++;
		}
	}
	map<int,int>::iterator it;
	for(it = maps.begin();it != maps.end();it++)
		vec.push_back(make_pair(it->first,it->second));

	sort(vec.begin(),vec.end(),cmp);
	vector<pair<int,int>>::iterator iit;
	// for(iit = vec.begin();iit != vec.end();iit++)
	// 	cout << iit->first <<" " << iit->second << endl;
	iit = vec.begin();
	cout << iit->first <<" " << iit->second << endl;
	return 0;
}