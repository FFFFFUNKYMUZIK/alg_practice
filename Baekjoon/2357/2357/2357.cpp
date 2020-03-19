#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MIN 0
#define MAX (1000000001ULL)

using namespace std;

typedef unsigned long long ull;
typedef struct node_t {
	ull minval;
	ull maxval;
} node;

node init(vector<node> & tree, vector<ull> & arr, int start, int end, int idx) {

	if (start == end) {
		tree[idx] = { arr[start], arr[start] };
	}
	else {
		node ln, rn;
		ln = init(tree, arr, start, (start + end) / 2, 2 * idx);
		rn = init(tree, arr, (start + end) / 2 + 1, end, 2 * idx + 1);
		tree[idx] = {min(ln.minval, rn.minval), max(ln.maxval, rn.maxval)};
	}

	return tree[idx];
}

node getminmax(vector<node>& tree, vector<ull>& arr, int start, int end, int idx, int left, int right) {

	if (right<start || left >end) return { MAX, MIN };
	else if (start >= left && end <= right) return tree[idx];
	
	node ln, rn;
	ln = getminmax(tree, arr, start, (start + end) / 2, 2*idx, left, right);
	rn = getminmax(tree, arr, (start + end) / 2 + 1, end, 2*idx + 1, left, right);
	return { min(ln.minval, rn.minval), max(ln.maxval, rn.maxval) };
}

node update(vector<node>& tree, vector<ull>& arr, int start, int end, int idx, int tar, ull val) {
	if (tar<start || tar>end) return tree[idx];

	if (start != end) {
		node ln, rn;
		ln = update(tree, arr, start, (start + end) / 2, 2 * idx, tar, val);
		rn = update(tree, arr, (start + end) / 2 + 1, end, 2 * idx + 1, tar, val);
		return { min(ln.minval, rn.minval), max(ln.maxval, rn.maxval) };
	}

	tree[idx] = { val, val };
	arr[tar] = val;

	return tree[idx];
	
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;

	cin >> N >> M;

	int idx = 0;
	vector<ull> arr(N, 0);
	while (idx < N) {
		cin >> arr[idx];
		idx++;
	}

	int h = ceil(log2(N)) + 1;
	vector<node> tree((1 << h) + 1 ,{MAX, MIN});
	init(tree, arr, 0, N - 1, 1);

	idx = 0;
	int a, b;
	node out;
	while (idx < M) {
		cin >> a >> b;
		out = getminmax(tree, arr, 0, N - 1, 1, a-1, b-1);
		printf("%lld %lld\n", out.minval, out.maxval );
		idx++;
	}


	return 0;
}