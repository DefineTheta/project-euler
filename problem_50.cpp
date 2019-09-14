#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

bool isPrime(long n){
	if(n % 2 == 0){
		return false;
	}

	for(int i = 3; i <= int(floor(sqrt(n))); i+=2){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

int main(){
	int cutOff;
	int maxSumCount = 0;
	int maxPrimeSum = 0;
	std::vector<int> ps{2,5,10,17};

	std::cin >> cutOff;

	auto t1 = std::chrono::high_resolution_clock::now();

	for(int i = 11; i < cutOff; i+=2){
		if(isPrime(i)){
			// std::cout << i << " is prime" << std::endl;

			// for (auto j = ps.begin(); j != ps.end(); ++j)
    	// 	std::cout << *j << ' ';

			// std::cout << std::endl;

			ps.push_back(ps.back() + i);
			std::vector<int>::iterator itr = std::find(ps.begin(), ps.end(), i);

			// std::cout << "Pos: " << ip << " Max count: " << maxSumCount << std::endl;

			if(itr != ps.end()){
				int p = std::distance(ps.begin(), itr);

				if(p > maxSumCount){
					maxSumCount = p + 1;
					maxPrimeSum = i;
				}
			}

			bool breakAll = false;

			for(int j = 1; j < ps.size() - maxSumCount; j++){
				for(int k = j + maxSumCount; k < ps.size(); k++){
					int d = ps[k] - ps[j];

					// std::cout << "K: " << k << " ps[k]: " << ps[k] << " J: " << j << " ps[j]: " << ps[j] << " ps[k] - ps[j] " << d << std::endl; 

					if(d == i){
						maxSumCount = k - j;
						maxPrimeSum = i;
					} else if(d > i){
						if(k == j + maxSumCount){
							breakAll = true;
						}

						break;
					}
				}

				if(breakAll){
					break;
				}
			}
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	std::cout << "Prime number with " << maxSumCount << " consecutive prime number sum below " << cutOff << " is: " << maxPrimeSum << std::endl; 
	std::cout << "Execution time: " << duration << std::endl;
}