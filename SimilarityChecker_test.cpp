#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityCheck, Input1_Null) {
	SimilarityChecker checker;
	int score = checker.checkSimilarity("", "AAA");

	EXPECT_EQ(0, score);
}

TEST(SimilarityCheck, Input2_Null) {
	SimilarityChecker checker;
	int score = checker.checkSimilarity("AAA","");

	EXPECT_EQ(0, score);
}
TEST(SimilarityCheck, INPUT_SAME_LENGTH) {
	SimilarityChecker checker;
	int score = checker.checkSimilarity("AAA", "BBB");

	EXPECT_EQ(40, score);
}