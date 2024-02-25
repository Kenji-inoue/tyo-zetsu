#pragma once
#include <string>
#include <vector>
#include <memory>

class ReplaceRuleInterface
{
public:
	virtual bool match(const std::string&, int) = 0;
	virtual std::string apply(const std::string&, int) = 0;
};

class NumberConverter
{
public:
	NumberConverter(const std::vector<std::shared_ptr<ReplaceRuleInterface>>& rules)
		: m_rules(rules) { }

	std::string convert(int n) {
		std::string carry;
		for (const auto& rule : m_rules) {
			if (rule->match(carry, n)) {
				carry = rule->apply(carry, n);
			}
		}
		return carry;
	}

private:
	std::vector<std::shared_ptr<ReplaceRuleInterface>> m_rules;
};

class CyclicNumberRule : public ReplaceRuleInterface
{
public:
	CyclicNumberRule(int base, const std::string& replacement)
		: m_base(base), m_replacement(replacement) { }

	virtual bool match(const std::string&, int number) override {
		return number % m_base == 0;
	};

	virtual std::string apply(const std::string& carry, int) override {
		return carry + m_replacement;
	};
private:
	int m_base;
	std::string m_replacement;
};

class PassThroughRule : public ReplaceRuleInterface
{
public:

	virtual bool match(const std::string& carry, int number) override {
		return carry == "";
	};

	virtual std::string apply(const std::string& carry, int number) override {
		return std::to_string(number);
	};
};