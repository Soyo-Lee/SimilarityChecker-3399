#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;
class SimilarityCheckTest : public Test {
public:
	static const int MAX_SCORE_LENGTH = 60;
	static const int MAX_SCORE_ALPHA = 40;
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckTest, LeftString_Null) {
	int score = checker.checkSimilarity("", "AAA");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, RightString_Null) {
	int score = checker.checkSimilarity("AAA","");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, INPUT_SAME_LENGTH_SAME_ALPHA) {
	int score = checker.checkSimilarity("AAA", "AAA");

	EXPECT_EQ(100 , score);
}

TEST_F(SimilarityCheckTest, LeftString_5_RightString_1) {
	int score = checker.checkSimilarity("AAAAA", "B");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, LeftString_5_RightString_4) {
	int score = checker.checkSimilarity("AAAAA", "BBBB");

	EXPECT_EQ(45, score);
}

TEST_F(SimilarityCheckTest, LeftString_5_RightString_2) {
	int score = checker.checkSimilarity("AAAAA", "BB");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, LeftString_4_RightString_5) {
	int score = checker.checkSimilarity("AAAA", "BBBBB");

	EXPECT_EQ(45, score);
}

TEST_F(SimilarityCheckTest, LeftString_ASD_RightString_DSA) {
	int score = checker.checkSimilarity("ASD", "DSA");

	EXPECT_EQ(100, score);
}

TEST_F(SimilarityCheckTest, LeftString_AA_RightString_AAE) {
	int score = checker.checkSimilarity("AA", "AAE");

	EXPECT_EQ(50, score);
}

TEST_F(SimilarityCheckTest, LeftString_AAE_RightString_AA) {
	int score = checker.checkSimilarity("AAE", "AA");

	EXPECT_EQ(50, score);
}

TEST_F(SimilarityCheckTest, LeftString_AA_RightString_AE) {
	int score = checker.checkSimilarity("AA", "AE");

	EXPECT_EQ(80, score);
}