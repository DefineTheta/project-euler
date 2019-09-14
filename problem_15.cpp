#include <iostream>
#include <vector>
#include <chrono>

long numOfPaths(int r, int c, int n, std::vector<std::vector<long>> *m){
	if(r >= n || c >= n){
		return 0;
	} else if(r == n - 1 && c == n - 1) {
		return 1;
	} else if(m->at(r)[c]){
		return m->at(r)[c];
	}

	long res = numOfPaths(r + 1, c, n, m) + numOfPaths(r, c + 1, n, m);
	(*m)[r][c] = res;

	// std::cout << "Row: " << r << " Col: " << c << " Paths: " << res << std::endl;

	return res;
}

int main(){
	int n;
	std::vector<std::vector<long>> *a = new std::vector<std::vector<long>>;

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::vector<long> c(n);
		a->push_back(c);
	}

	auto t1 = std::chrono::high_resolution_clock::now();
	long res = numOfPaths(0, 0, n, a);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	std::cout << "Total number of paths: " << res << std::endl;
	std::cout << "Execution time: " << duration << std::endl;
}