#include <string>

using std::string;

class SimilarityChecker {
public:
	int checkSimilarity(string input1, string input2)
	{
		int length1 = input1.length();
		int length2 = input2.length();

		if (length1 == length2)
		{
			return 40;
		}
		if (length2 > length1) swap(length1, length2);

		if (length1 >= (length2 * 2))
			return 0;
		int gap = getGap(length1, length2);

		double score = ((double)gap / length2) * 40;
		return score;
	}
	int getGap(int length1, int length2)
	{
		return length1 - length2;
	}

	void swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
};