#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long int ll;
vector< pair<int, int> >vet;
vector< int > indices, result;

double dist(pair<int, int>p1, pair<int, int>p2){
	return 16 + sqrt( (p1.F - p2.F)*(p1.F - p2.F) + (p1.S - p2.S)*(p1.S - p2.S) );
}

main()
{
	int n, x, y, cases = 1;
	
	while(cin >> n && n)
	{
		double best = 2000000;
		vet.clear();
		indices.clear();
		result.clear();
		
		for(int i = 0 ; i < n; i++){
			cin >> x >> y;
			vet.push_back( {x, y} );
			indices.push_back(i);
		}
		
		double sum;
		do{
			sum = 0;
			for(int i = 0; i < n-1; i++)
				sum += dist(vet[indices[i]], vet[indices[i+1]]);
				
			if (sum < best){
				best = sum;
				result = indices;
			}
	
		}while(next_permutation(indices.begin(), indices.end()));
		
		cout << "**********************************************************" << endl;
		cout << "Network #" << cases++ << endl;
		
		for(int i = 0; i < result.size()-1; i++)
		{
			cout << "Cable requirement to connect (" << vet[result[i]].first << "," << vet[result[i]].second;
			cout << ") to (" << vet[result[i+1]].first << "," << vet[result[i+1]].second;
			cout << ") is " << fixed << setprecision(2) << dist(vet[result[i]], vet[result[i+1]]) << " feet." << endl;
		}
		
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << best << "." << endl;
	}
}
