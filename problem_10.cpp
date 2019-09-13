#include <iostream>
#include <cmath>

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
	long primeSum = 2;
	long count = 3;
	int primeCutOff;

	std::cin >> primeCutOff;

	while(count < primeCutOff){
		if(isPrime(count)){
			primeSum += count;
		}

		count+=2;
	}

	std::cout << "Sum of all prime numbers below " << primeCutOff << " is: " << primeSum << std::endl;
}