#include <string>

using std::string;

class SimilarityChecker {
public:
	static const int MAX_SCORE_LENGTH = 60;
	int checkSimilarity(string input1, string input2)
	{
		int length1 = input1.length();
		int length2 = input2.length();

		if (length1 == length2)	return MAX_SCORE_LENGTH;
		if (length2 > length1) swap(length1, length2);
		if (length1 >= (length2 * 2)) return 0;
		return (1 - getGap(length1, length2) / length2) * MAX_SCORE_LENGTH;
	}

	void swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	double getGap(int length1, int length2)
	{
		return (double)length1 - length2;
	}
};