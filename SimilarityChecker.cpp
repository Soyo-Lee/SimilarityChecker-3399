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
		if (length2 > length1)
		{
			//swap
			int temp = length1;
			length1 = length2;
			length2 = temp;
		}

		int gap = length1 - length2;
		if (gap > length2)
			return 0;
		if (length1 == 0)
			return 0;
		double score = ((double)gap / length2) * 40;
		return score;


			
		return 0;
	}
};