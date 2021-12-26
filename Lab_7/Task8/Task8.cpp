#include <iostream>
#include <string>
using namespace std;
int dlin = 0;
std::string sole(long long n) {
	std::string result = "";
	if (n == 0) {
		result = "0";
		dlin = 0;
	}
	while (n > 0) {
		if (n == 2) {
			result = "10" + result;
			dlin += 2;
			break;
		}
		else {
			dlin++;
			result = char(n % 2 + '0') + result;
		}
		n /= 2;
	}
	return result;
}
int main() {

	
	int sum = 0;
	for (unsigned long long i = 1; i < 1e8; i++) { // i<=1e8
		unsigned long long j = 0;
		
		dlin = 0;
		string mystring = sole(i);
		string answ = mystring;
		
		int copydlin = dlin;
		bool flag = true;
		unsigned long long ten = j, two = j;
		while (dlin>0&&copydlin>0) {
			char x = (int(mystring[dlin-1])-48)%2==1?'1':'0';
			if (!(x == answ[--copydlin])) {
				flag = false;
				break;

			}
			int carry = 0;
			for (int i = 0; mystring[i]; i++) {
				long long cur = int(mystring[i]) - 48 + carry * 10;
				mystring[i] = char(cur / 2 + 48);
				carry = int(cur % 2);
			}

			if (mystring[0] == '0') {
				dlin--;
				for (int i = 0; mystring[i]; i++) {
					if (mystring[i + 1])
						mystring[i] = mystring[i + 1];
					else
						mystring[i] = '\0';
				}
			}
		}
		if (flag) {
			sum++;
			std::cout << sum<<" - " << answ << "\n";
		}




		if (sum == 10000) {
			cout<<"\n\nWTF\n";
			break;
		}
	}
}