#include <bits/stdc++.h>
using namespace std;
int main() {

	int n;
	string asp;
	cin >> n >> asp;
	vector<pair<int, int>> checker(n, {INT_MAX, INT_MAX});
	for (int ms = 0; ms < n; ms++)
	{
		if (asp[ms] == 'A')
		{
			int t = 0;
			int j = ms - 1;
			if (j >= 0)
			{
				for (j; j >= 0; j--)
				{
					if (asp[j] == '-')
					{
						checker[j].first = min(checker[j].first, t);
					}
					else if (asp[j] == 'A' || asp[j] == 'B')
					{
						break;
					}
					++t;
				}
			}
		}
		else if (asp[ms] == 'B')
		{
			int t = 0;
			int j = ms + 1;
			if (j < n)
			{
				for (j; j < n; j++)
				{
					if (asp[j] == '-')
					{
						checker[j].second = min(checker[j].second, t);
					}
					else if (asp[j] == 'B' || asp[j] == 'A')
					{
						break;
					}
					t++;
				}
			}
		}
	}
	int a_count = 0;
	int b_count = 0;
	for (int mt = 0; mt < n; mt++)
	{
		int x = checker[mt].first;
		int y = checker[mt].second;
		if (asp[mt] == 'A')
		{
			a_count++;
		}
		else if (asp[mt] == 'B')
		{
			b_count++;
		}
		if (asp[mt] == '-')
		{
			if (x > y)
			{
				b_count++;
			}
			else if (x < y)
			{
				a_count++;
			}
		}
	}
	if (a_count > b_count)
	{
		cout << "A";
	}
	else if (b_count > a_count)
	{
		cout << "B";
	}
	else
	{
		cout << "Coalition government";
	}
}