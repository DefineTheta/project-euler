#include <iostream>
#include <cmath>

long triangleNum(long prevSum, long n){
	return prevSum + n;
}

int numOfDivisors(int n){
	int count = 2; 

	for(int i = 2; i <= int(floor(sqrt(n))); i++){
		if(n % i == 0){
			count+=2;
		}
	}

	return count;
}

int main(){
	int divCountThreshold;
	long tNum = 1;
	long count = 2;

	std::cin >> divCountThreshold;

	while(true){
		tNum = triangleNum(tNum, count);
		
		if(numOfDivisors(tNum) > divCountThreshold){
			break;
		}

		count++;
	}

	std::cout << "Value of the first triangle number to have over " << divCountThreshold << " divisors is: " << tNum << std::endl;
}