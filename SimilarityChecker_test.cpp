#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityCheck, test1) {
	SimilarityChecker checker;
	int score = checker.checkSimilarity("", "AAA");

	EXPECT_EQ(0, score);
}
