#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;
class SimilarityCheckTest : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckTest, Input1_Null) {
	int score = checker.checkSimilarity("", "AAA");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, Input2_Null) {
	int score = checker.checkSimilarity("AAA","");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, INPUT_SAME_LENGTH) {
	int score = checker.checkSimilarity("AAA", "BBB");

	EXPECT_EQ(40, score);
}

TEST_F(SimilarityCheckTest, Input1_5_Input2_1) {
	int score = checker.checkSimilarity("AAAAA", "B");

	EXPECT_EQ(0, score);
}

TEST_F(SimilarityCheckTest, Input1_5_Input2_4) {
	int score = checker.checkSimilarity("AAAAA", "BBBB");

	EXPECT_EQ(10, score);
}

TEST_F(SimilarityCheckTest, Input1_5_Input2_2) {
	int score = checker.checkSimilarity("AAAAA", "BB");

	EXPECT_EQ(30, score);
}