#include <iostream>
#include <string>
#include <memory>
#include "Rule.hpp"

void enterText(std::string& text)
{
	std::cout << "Enter natural number:";
	std::cin >> text;
}

bool isValidInteger(const std::string& text)
{
	try
	{
		const auto integer = std::stoi(text);
		if (integer >= 0)
		{
			return true;
		}
		else
		{
			std::cerr << "Error:" << text << " is inavalid range as entered value. Value should be -1 or positive integer." << std::endl;
			return false;
		}
	}
	catch (const std::invalid_argument& invalid_argument)
	{
		std::cerr << "Error:" << text << " is invalid as integer." << std::endl;
		return false;
	}
	catch (const std::out_of_range& invalid_argument)
	{
		std::cerr << "Error:" << text << " is out of range as integer." << std::endl;
		return false;
	}
}

int enterInteger()
{
	std::string text;
	enterText(text);
	while (!isValidInteger(text)){
		enterText(text);
	}
	return std::stoi(text);
}

int main()
{
    
	std::vector<std::shared_ptr<ReplaceRuleInterface>> rules;
	rules.push_back(std::make_shared<CyclicNumberRule>(2, "Fizz"));
	rules.push_back(std::make_shared<CyclicNumberRule>(3, "Buzz"));
	rules.push_back(std::make_shared<CyclicNumberRule>(5, "Yeah"));
	rules.push_back(std::make_shared<PassThroughRule>());
	
	const auto fizzBuzz = std::make_unique<NumberConverter>(rules);

    while (true) {
		const int number = enterInteger();
		
		if (number == 0) {
			break;
		}

		std::cout << fizzBuzz->convert(number) << "\n";
    }
    return 0;
}

