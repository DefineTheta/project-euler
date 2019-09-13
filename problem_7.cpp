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
	int primeCount = 1;
	long count = 3;
	int primeNumPos;

	std::cin >> primeNumPos;

	while(primeCount != primeNumPos){
		if(isPrime(count)){
			primeCount++;
		}

		count+=2;
	}

	std::cout << "Prime number at position " << primeNumPos << " is: " << count - 2 << std::endl;
}