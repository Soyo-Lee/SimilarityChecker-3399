#include <string>

using std::string;

class SimilarityChecker {
public:
	int checkSimilarity(string input1, string input2)
	{
		int lenngth1 = input1.length();
		int lenngth2 = input2.length();

		if (lenngth1 == lenngth2)
			return 40;
		else
		    return 0;
	}
};