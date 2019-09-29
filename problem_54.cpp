#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <fcntl.h>
#include <stdlib.h> 
#include <unistd.h>

typedef int (*FnPtr)(std::unordered_map<char, std::vector<int>>);

int royalFlush(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int> n{10, 11, 12, 13, 14};
	std::vector<int>::iterator vitr;

	for(int i = 0; i < s.size(); i++){
		std::vector<int> sc = h[s[i]];

		if(sc.size() == 5){
			for(int j = 0; j < 5; j++){
				if(std::find(sc.begin(), sc.end(), n[j]) == sc.end()){
					return -1;
				}
			}

			return 0;
		} else if(sc.size() > 0){
			return -1;
		}
	}
}

int straightFlush(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};

	for(int i = 0; i < s.size(); i++){
		std::vector<int> sc = h[s[i]];

		if(sc.size() == 5){
			std::sort(sc.begin() ,sc.end());

			int pn = sc[0];
			int m = pn;

			for(int j = 1; j < 5; j++){
				if(sc[j] != pn + 1){
					return -1;
				}

				pn = sc[j];
				
				if(pn > m){
					m = pn;
				}
			}

			return m;
		} else if(sc.size() > 0){
			return -1;
		}
	}
}

int fourOfAKind(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;

	for(int i = 2; i <= 14; i++){
		int ca = 0;

		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				ca++;
			} else {
				break;
			}
		}

		if(ca == 4){
			return i;
		}
	}

	return -1;
}

int fullHouse(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;
	int pair = -1;
	int three = -1;

	for(int i = 2; i <= 14; i++){
		int ca = 0;

		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				ca++;
			}
		}

		if(ca == 2){
			pair = i;
		} else if(ca == 3){
			three = i;
		}
	}

	if(pair != -1 && three != -1){
		return three;
	} else {
		return -1;
	}
}

int flush(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};

	for(int i = 0; i < s.size(); i++){
		std::vector<int> sc = h[s[i]];

		if(sc.size() == 5){
			std::sort(sc.begin(), sc.end());
			
			return sc[4];
		}
	}

	return -1;
}

int straight(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;
	bool f = false;
	int t = 0;
	int cc = 0;

	for(int i = 2; i <= 14; i++){
		for(int j = 0; j < s.size(); j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				f = true;
				cc++;
				t == i;
			} else if(f){
				if(cc == 5){
					return t;
				} else {
					return -1;
				}
			}
		}		
	}

	return -1;
}

int threeOfAKind(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;

	for(int i = 2; i <= 14; i++){
		int ca = 0;

		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				ca++;
			}
		}

		if(ca == 3){
			return i;
		}
	}

	return -1;
}

int twoPairs(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;
	int po = -1;
	int pt = -1;

	for(int i = 2; i <= 14; i++){
		int ca = 0;

		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				ca++;
			}
		}

		if(ca == 2){
			if(po == -1){
				po = i;
			} else {
				pt = i;
			}
		}
	}

	if(po != -1 && pt != -1){
		if(po > pt){
			return po;
		} else {
			return pt;
		}
	} else {
		return -1;
	}
}

int onePair(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;

	for(int i = 2; i <= 14; i++){
		int ca = 0;

		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				ca++;
			}
		}

		if(ca == 2){
			return i;
		}
	}

	return -1;
}

int highCard(std::unordered_map<char, std::vector<int>> h){
	std::vector<char> s{'C', 'H', 'S', 'D'};
	std::vector<int>::iterator vitr;
	int lc = 0;

	for(int i = 2; i <= 14; i++){
		for(int j = 0; j < 4; j++){
			std::vector<int> sc = h[s[j]];

			vitr = std::find(sc.begin(), sc.end(), i);

			if(vitr != sc.end()){
				lc = i;
			}
		}
	}

	return lc;
}

std::vector<int> handVec(std::unordered_map<char, std::vector<int>> h){
	std::unordered_map<char, std::vector<int>>::iterator itr;
	std::vector<int> r;

	for(itr = h.begin(); itr != h.end(); itr++){
		std::vector<int> v = itr->second; 

		if(v.size() != 0){
			for(int i = 0; i < v.size(); i++){
				r.push_back(v[i]);
			}
		}
	}

	return r;
}

int compareHands(std::unordered_map<char, std::vector<int>> ho, std::unordered_map<char, std::vector<int>> ht, std::unordered_map<std::string, FnPtr> *f){
	int playerOneHandType = -1;
	int playerTwoHandType = -1;
	int playerOneWinCard = 0;
	int playerTwoWinCard = 0;
	std::vector<std::string> c{"Royal Flush", "Straight Flush", "Four of a Kind",
	"Full House", "Flush", "Straight", "Three of a Kind", "Two Pairs",
	"One Pair", "High Card"};

	for(int i = 0; i < c.size(); i++){
		playerOneWinCard = (*f)[c[i]](ho);

		if(playerOneWinCard != -1){
			playerOneHandType = i;
			break;
		}
	}

	for(int i = 0; i < c.size(); i++){
		playerTwoWinCard = (*f)[c[i]](ht);

		if(playerTwoWinCard != -1){
			playerTwoHandType = i;
			break;
		}
	}

	if(playerOneHandType == 5 || playerTwoHandType == 5){
		std::cout << "Player one: " << c[playerOneHandType] << " cards: " << playerOneWinCard << std::endl;
		std::cout << "Player two: " << c[playerTwoHandType] << " cards: " << playerTwoWinCard << std::endl;
	}

	if(playerOneHandType < playerTwoHandType){
		return 1;
	} else if(playerOneHandType > playerTwoHandType){
		return 2;
	} else {
		if(playerOneWinCard > playerTwoWinCard){
			// std::cout <<" cards: " << playerOneWinCard << std::endl;
			// std::cout << " cards: " << playerTwoWinCard << std::endl;
			return 1;
		} else if(playerOneWinCard < playerTwoWinCard){
			return 2;
		} else {
			std::vector<int> poc = handVec(ho);
			std::vector<int> ptc = handVec(ht);

			std::sort(poc.begin(), poc.end(), std::greater<int>());
			std::sort(ptc.begin(), ptc.end(), std::greater<int>());

			// for(int i = 0; i < poc.size(); i++){
			// 	std::cout << poc[i] << " ";
			// }

			// std::cout << std::endl;

			// for(int i = 0; i < ptc.size(); i++){
			// 	std::cout << ptc[i] << " ";
			// }

			// std::cout << std::endl;

			for(int i = 0; i < 5; i++){
				if(poc[i] > ptc[i]){
					return 1;
				} else if(poc[i] < ptc[i]){
					return 2;
				}
			}
		}
	}
}

int cardNum(char cn){
	int n = 0;

	if(cn == 'T'){
		n = 10;
	}	else if(cn == 'J'){
		n = 11;
	} else if(cn == 'Q'){
		n = 12;
	} else if(cn == 'K'){
		n = 13;
	} else if(cn == 'A'){
		n = 14;
	} else {
		n = cn - '0';
	}

	return n;
}

std::unordered_map<char, std::vector<int>> convertHand(std::vector<std::string> h){
	std::vector<int> v;
	std::unordered_map<char, std::vector<int>> r{{'C', v}, {'H', v}, {'S', v}, {'D', v}};

	for(int i = 0; i < h.size(); i++){
		char cn = h[i][0];

		r[h[i][1]].push_back(cardNum(cn));
	}

	return r;
}

int main(int argc, char** argv) {
	int fd = open(argv[1], O_RDONLY); 	//open file on file descriptor
	int newfd = dup2(fd, 0);             //replace stdin with file

	std::string p1c1, p1c2, p1c3, p1c4, p1c5, p2c1, p2c2, p2c3, p2c4, p2c5;

	int playerOneWins = 0;
	int c = 1;
	std::unordered_map<std::string, FnPtr> f{{"High Card", highCard},
	{"One Pair", onePair}, {"Two Pairs", twoPairs}, {"Three of a Kind", threeOfAKind},
	{"Straight", straight}, {"Flush", flush}, {"Full House", fullHouse},
	{"Four of a Kind", fourOfAKind}, {"Straight Flush", straightFlush}, {"Royal Flush", royalFlush}};

	while(std::cin >> p1c1 >> p1c2 >> p1c3 >> p1c4 >> p1c5 >> p2c1 >> p2c2 >> p2c3 >> p2c4 >> p2c5){
		std::vector<std::string> playerOneHand{p1c1, p1c2, p1c3, p1c4, p1c5};
		std::vector<std::string> playerTwoHand{p2c1, p2c2, p2c3, p2c4, p2c5};

		std::unordered_map<char, std::vector<int>> playerOneHandMap = convertHand(playerOneHand);
		std::unordered_map<char, std::vector<int>> playerTwoHandMap = convertHand(playerTwoHand);

		int winner = compareHands(playerOneHandMap, playerTwoHandMap, &f);

		std::cout << "Game number: " << c << std::endl;

		if(winner == 1){
			playerOneWins++;
			std::cout << "Player one won: " << c << std::endl;
		}

		c++;
	}

	std::cout << "Total number of games played: " << c - 1 << std::endl;
	std::cout << "Player one won " << playerOneWins << " games" << std::endl;
}