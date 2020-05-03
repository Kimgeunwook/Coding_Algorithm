#include <stdio.h>

int N, M;
#define MAXT (100002*2*2)
int tree[MAXT];
int lazy[MAXT];

void propagate(int node, int rs, int re)
{
	int m = (rs + re) / 2;

	if (lazy[node] == 0) return;

	if (rs != re)
	{
		lazy[node * 2] = (m - rs + 1) - lazy[node * 2];
		lazy[node * 2 + 1] = (re - m) - lazy[node * 2 + 1];
	}

	lazy[node] = 0;
	tree[node] = (re - rs + 1) - tree[node];
}

void updateTree(int node, int s, int e, int us, int ue)
{
	int m;

	propagate(node, s, e);

	if (us > e || s > ue) return;
	if (us <= s && e <= ue)
	{
		lazy[node] = (e - s + 1) - lazy[node];
		propagate(node, s, e);
		return;
	}

	m = (s + e) / 2;
	updateTree(node * 2, s, m, us, ue);
	updateTree(node * 2 + 1, m + 1, e, us, ue);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int qs, int qe)
{
	int m, left, right;

	propagate(node, s, e);

	if (s > qe || e < qs) return 0;
	if (qs <= s && e <= qe)
	{
		return tree[node];
	}

	m = (s + e) / 2;
	left = query(node * 2, s, m, qs, qe);
	right = query(node * 2 + 1, m + 1, e, qs, qe);

	return left + right;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int O = 0, S = 0, T = 0;
		scanf("%d %d %d", &O, &S, &T);
		if (O == 0)
		{
			updateTree(1, 1, N, S, T);
		}
		else if (O == 1)
		{
			printf("%d\n", query(1, 1, N, S, T));
		}
	}

	return 0;
}