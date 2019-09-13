#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>
#include <string>
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

bool isTruncatable(long n, std::unordered_set<int> *pns){
	std::string sn = std::to_string(n);

	for(int i = 0; i < sn.length(); i++){
		int n1 = stoi(sn.substr(0, sn.length() - i));
		int n2 = stoi(sn.substr(sn.length() - i - 1, i + 1));

		if(pns->find(n1) == pns->end()){
			if(isPrime(n1)){
				pns->insert(n1);
			} else {
				return false;
			}
		}

		if(pns->find(n2) == pns->end()){
			if(isPrime(n2)){
				pns->insert(n2);
			} else {
				return false;
			}
		}
	}

	return true;
}

void getCombs(std::vector<int> *c, int n){
	std::vector<int> co{1,3,7,9};
	std::vector<int> oc = *c;
	c->clear();

	if(n <= 0){
		c->push_back(0);
		return;
	}

	for(int i = 0; i < oc.size(); i++){
		for(int j = 0; j < 4; j++){	
			c->push_back(co[j] * int(pow(10, n - 1)) + oc[i]);
		}
	}
}

int main(){
	long sum = 0;
	int nCount = 0;
	int nLength = 2;
	std::unordered_set<int> *pn = new std::unordered_set<int>;
	std::vector<int> *combs = new std::vector<int>;
	std::vector<int> fd{2,3,5,7};
	std::vector<int> ld{3,7};

	auto t1 = std::chrono::high_resolution_clock::now();

	while(nCount != 11){
		getCombs(combs, nLength - 2);

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < combs->size(); k++){
					long cn = fd[i] * int(pow(10, nLength - 1)) + combs->at(k) * 10 + ld[j];

					if(isTruncatable(cn, pn)){
						sum += cn;
						nCount++;
						// std::cout << "Truncable number: " << cn << std::endl;
					}
				}
			}
		}

		nLength++;
	}	

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

	std::cout << "Sum of eleven truncable prime numeer is: " << sum << std::endl;
	std::cout << "Execution time: " << duration << std::endl;
}