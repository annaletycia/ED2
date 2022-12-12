//Throwing cards away I - 10935

#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int N;
	while(scanf("%d", &N) && N!= 0)
	{		
		queue <int> q;
		vector <int> c;

		for(int j=1; j <= N; j++) 
			q.push(j);
		
		int Qtam = q.size();
		int Ctam = c.size();

		while(Qtam>2)
		{
			c.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		if(Qtam==2)
		{
			c.push_back(q.front());
			q.pop();
		}
		
		printf("Discarded cards:");
		for(int i=0; i < Ctam; i++)
		{
			if(i>0) 
				printf(",");
			printf(" %d", c[i]);
		}
		printf("\n");

		printf("Remaining card: %d\n", q.front());
	}
	return 0;
}
