// PB Link : https://codeforces.com/problemset/problem/1851/A

#include  <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int n, m, k, h;
	scanf("%d", &t);

	while (t--){
		int can_have_con = 0;

		scanf("%d %d %d %d", &n, &m, &k, &h);

		int person_heights[n+1];
		int available_persons[n+1] = {0};

		for(int i=1; i<=n; i++){
			scanf("%d", &person_heights[i]);
			person_heights[i] = abs( person_heights[i] - h);
		}

		for (int step1=1; step1 <= m; step1++){
			for (int step2 = step1+1; step2 <= m; step2++){
				int step_diff;
				step_diff = abs(step1 - step2) * k;
				for (int i=1; i<=n; i++){
					if (person_heights[i] == step_diff){
						available_persons[i] = 1;
					}
				}
			}
		}

		for (int i=1; i <= n; i++){
			can_have_con += available_persons[i];
			//printf("%d ", available_persons[i]);
		}

		printf("%d\n", can_have_con);

	}

	return 0;
}
