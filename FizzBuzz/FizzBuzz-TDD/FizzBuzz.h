#pragma once
#include <string>

class FizzBuzz {
public:
	std::string Convert(int n) {
		if (n % 15 == 0) {
			return "FizzBuzz";
		}
		else if (n % 3 == 0) {
			return "Fizz";
		}
		else if (n % 5 == 0) {
			return "Buzz";
		}
		else {
			return std::to_string(n);
		}
		
	}
private:
};