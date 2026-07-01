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
		else if(length1 > length2)
		{
			int gap = length1 - length2;
			if (gap > length2)
				return 0;
			if (length1 == 0)
				return 0;
			double score = ((double)gap / length2) * 40;
			return score;
		}
		else
		{
			int gap = length2 - length1;
			if (gap > length1)
				return 0;
			if (length2 == 0)
				return 0;
			double score = ((double)gap / length1) * 40;
			return score;
		}
			
		return 0;
	}
};