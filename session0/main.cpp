
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "exploreSpace.hpp"
#include "diplomacy.hpp"

using namespace testing;
class IDiplomacyMock : public IDiplomacy
{
public:
    MOCK_METHOD1(SayHello, bool(std::string num));
    MOCK_METHOD0(ExchangeGift, void());
    MOCK_METHOD1(SayBye, bool(std::string num));
};

class ExploreSpaceTest : public Test
{
protected:
    void SetUp() override
    {
        IDiplomacyMockPtr_ = std::make_shared<IDiplomacyMock>();
        ExploreSpacePtr_ = std::make_shared<ExploreSpace>(IDiplomacyMockPtr_);
    }

    std::shared_ptr<IDiplomacyMock> IDiplomacyMockPtr_;
    std::shared_ptr<ExploreSpace> ExploreSpacePtr_;
};

TEST_F(ExploreSpaceTest, ExploreSpaceSuccess)
{

    EXPECT_CALL(*IDiplomacyMockPtr_, SayHello("Hello"))
        .WillOnce(Return(true));
    EXPECT_CALL(*IDiplomacyMockPtr_, ExchangeGift());
    EXPECT_CALL(*IDiplomacyMockPtr_, SayBye("see you"))
        .WillOnce(Return(true));
    ExploreSpacePtr_->ExploreStart();
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
