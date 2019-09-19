#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <chrono>

bool isPrime(long n){
	if(n % 2 == 0 && n != 2){
		return false;
	}

	for(int i = 3; i <= int(floor(sqrt(n))); i+=2){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

std::set<int> digitSet(long n){
	std::string sn = std::to_string(n);
	std::set<int> r;

	for(int i = 0; i < sn.length(); i++){
		r.insert(sn[i] - '0');
	}

	return r;
}

std::set<long> pandigitalNums(int n){
	std::set<long> oldSet;

	for(int i = 1; i <= n; i++){
		if(i % 2 != 0 and i != 5){
			oldSet.insert(i);
		}
	}

	for(int i = 2; i <= n; i++){
		std::set<long> newSet;
		
		for(long num : oldSet){
			// std::cout << "I: " << i << " Pal: " << num << std::endl;

			std::set<int> d = digitSet(num);
			std::set<int>::iterator itr;
			std::set<int>::iterator dEnd = d.end();

			for(int j = 1; j <= n; j++){
				itr = d.find(j);
				
				if(itr == dEnd){
					newSet.insert(j * pow(10, i - 1) + num);
				}
			}
		}

		oldSet = newSet;
	}

	return oldSet;
}

int main(){
	std::set<long> pn;
	std::set<long>::reverse_iterator itr;
	long lpp = 0;
	bool found = false;
	
	auto t1 = std::chrono::high_resolution_clock::now();

	for(int i = 9; i > 1; i--){
		pn = pandigitalNums(i);

		for(itr = pn.rbegin(); itr != pn.rend(); itr++){
			// std::cout << "Pal: " << *itr << std::endl;

			if(isPrime(*itr)){
				lpp = *itr;
				found = true;
				break;
			}
		}

		if(found){
			break;
		}
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	std::cout << "Largest n-digit pandigital prime is: " << lpp << std::endl;
	std::cout << "Execution time: " << duration << std::endl;
}