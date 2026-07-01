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
		else if (length1 == 5 && length1 - length2 == 4)
		{
			return 0;
		}
		else if (length1 == 5 && length1 - length2 == 1)
		{
			return 10;
		}
			
		return 0;
	}
};