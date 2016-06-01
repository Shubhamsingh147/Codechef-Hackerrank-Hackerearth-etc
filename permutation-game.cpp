#include <iostream>

using namespace std;

int tree[1 << 15];
int cache[1 << 15];
int numbers[15];
int n;

int solve(int node) {

    if (tree[node] != -1){
	
	return tree[node];
    }
    else {
	tree[node] = 0;
	for (int i = 0; i < n; i++){

	    int not_leaf_node = node & (1 << i);
	    if (not_leaf_node){
		if ( solve(node - (1 << i)) == 0){

		    tree[node] = 1;
		    break;
		}
	    }
	}
    }
    
    return tree[node];
    
}

int main() {
    
    int n;
    cin >> n;
	for (int i = 0; i < n; i++){    
	    cin >> numbers[i];
	}
	
	tree[0] = 0;
	cache[0] = 0;
	for (int i = 0; i < n; i++) {	    
	    int offset = (1 << i);
	    for (int j = 0; j < offset; j++){
		if ( (tree[j] == 0) && (numbers[i] > cache[j]) ){
	    tree[offset + j] = 0;		    
		}
		else {
		    tree[offset + j] = -1;
		}
		cache[offset + j] = numbers[i];
		
	    }
	}
	bool AMAN_wins = solve((1 << n) - 1);

	if(AMAN_wins){
	    
	    cout << "AMAN" << endl;
	}
	else {
	    
	    cout << "JASBIR" << endl;
	}
    
    return 0;
}