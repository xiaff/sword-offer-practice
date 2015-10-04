/*
	面试题11:数值的整数次方
	实现函数 double Power(double base, int exponent)，求base的exponent次方。
	不得使用库函数，同时不需要考虑大数问题。
*/

class Solution
{
public:
	bool Invalid_Input = false;

	double Power(double base, int exponent) {
		Invalid_Input = false;
		if (equal(base, 0.0) && exponent <= 0) {
			Invalid_Input = true;
			return 0.0;
		}

		unsigned int absExponent;
		if (exponent<0) {
			absExponent = (unsigned int)(-exponent);
		}
		else {
			absExponent = (unsigned int)exponent;
		}

		double result = PowerWithUnsignedExponent(base, absExponent);

		if (exponent<0) {
			result = 1.0 / result;
		}

		return result;
	}

private:
	bool equal(double a, double b) {
		if ((a - b<0.0000001) && (b - a<0.0000001)) {
			return true;
		}
		else {
			return false;
		}
	}

	double PowerWithUnsignedExponent(double base, unsigned int exponent) {
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base;
		}

		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result = result*result;
		if ((exponent & 0x1) == 1) {
			result *= base;
		}
		return result;
	}
};