#include "pch.h"
#include "FizzBuzz.h"

FizzBuzz fizzBuzz;

TEST(test_1, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(1), "1");
}

TEST(test_2, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(2), "2");
}

TEST(test_Fizz, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(3), "Fizz");
}

TEST(test_Buzz, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(5), "Buzz");
}

TEST(test_6, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(6), "Fizz");
}

TEST(test_10, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(10), "Buzz");
}

TEST(test_15, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(15), "FizzBuzz");
}

TEST(test_30, FizzBuzz) {
	EXPECT_EQ(fizzBuzz.Convert(30), "FizzBuzz");
}
