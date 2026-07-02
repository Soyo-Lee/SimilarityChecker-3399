#include <string>

using std::string;

class SimilarityChecker {
public:
	static const int MAX_SCORE_LENGTH = 60;
	static const int MAX_SCORE_ALPHA = 40;
	
	int checkSimilarity(string LeftString, string RightString)
	{
		return getScoreAlpha(LeftString, RightString) + getScoreLength(LeftString, RightString);
	}

	int getScoreLength(const string& LeftString, const string& RightString)
	{
		int length1 = LeftString.length();
		int length2 = RightString.length();
		
		if (length1 == length2) {
			if (length1 == 0)
				return 0;
			return MAX_SCORE_LENGTH;
		}

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

	int getScoreAlpha(const string& LeftString, const string& RightString) const {
		int SameCnt = 0;
		int TotalCnt = 0;
		
		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			if (LeftString.find(ch) != string::npos)
			{
				if (RightString.find(ch) != string::npos)
					SameCnt++;
				TotalCnt++;
			}
			else if(RightString.find(ch) != string::npos)
				TotalCnt++;
		}

		if (TotalCnt == 0)
			return 0;
		return ((double)SameCnt / TotalCnt) * MAX_SCORE_ALPHA;;
	}

	double getGap(int length1, int length2)
	{
		return (double)length1 - length2;
	}	
};