#include <iostream>
#include <cmath>

bool isPrime(long n){
	for(int i = 2; i <= int(floor(sqrt(n))); i++){
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