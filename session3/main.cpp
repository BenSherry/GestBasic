
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "exploreSpace.hpp"
#include "diplomacy.hpp"
#include "gift.hpp"

using namespace testing;
using ::testing::_;
class IDiplomacyMock : public IDiplomacy
{
public:
    MOCK_METHOD2(SayHello, bool(std::string, std::string&));
    MOCK_METHOD1(ExchangeGift, Gifts(Gifts&));
    MOCK_METHOD1(SayBye, bool(std::string));
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

MATCHER_P(GiftChecker, expectGift, "")
{
    Gifts standGifts = expectGift;
    // auto realGift =  const_cast<Gifts&>(arg);
    auto realGift = arg;
    if (standGifts.GetName() != realGift.GetName() ||
    standGifts.GetOrigin() != realGift.GetOrigin() ||
    standGifts.GetPurpose() != realGift.GetPurpose())
    {
        return false;
    }
    return true;
}

TEST_F(ExploreSpaceTest, getnum)
{
    std::string paraHello;
    std::string paraBye;
    Gifts alienGifts{"stone", "Thanos", "Govern"};
    Gifts expectGift{"pen", "china", "writting"};
    EXPECT_CALL(*IDiplomacyMockPtr_, SayHello(_,_))
        .WillOnce(DoAll(SaveArg<0>(&paraHello),
            SetArgReferee<1>("Hello, my earth friends"),
            Return(true)));
    EXPECT_CALL(*IDiplomacyMockPtr_, ExchangeGift(GiftChecker(expectGift)))
        .WillOnce(Return(alienGifts));
    EXPECT_CALL(*IDiplomacyMockPtr_, SayBye("see you"))
        .WillOnce(DoAll(SaveArg<0>(&paraBye), Return(true)));
    ExploreSpacePtr_->ExploreStart();
    EXPECT_EQ(paraHello, "Hello");
    EXPECT_EQ(paraBye,"see you");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
