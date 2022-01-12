#include<bits\stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		char c[n];
		double val[n];
		for(int i = 0; i < n; i++) cin >> c[i] >> val[i];
		int m;
		cin >> m;
		double ans = 0.0;
		string s;
		while(m--)
		{
			getline(cin,s);
			for(int i = 0; i < s.length(); i++) 
			{
				for(int j = 0; j < n; j++)
				{
					if(s[i] == c[j]) 
					{
						ans += val[j];
						//break;
					}
				}
			}
		}
		cout << ans / 100.0 << "$" << endl;
	}
}
