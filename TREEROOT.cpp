#include <cstdio>

int main(){
	int T, N, id, sum, root;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		root=0;
		while(N--){
			scanf("%d%d", &id, &sum);
			root+=id-sum;
		}
		printf("%d\n", root);
	}
	return 0;
}