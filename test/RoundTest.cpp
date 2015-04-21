#include <gtest/gtest.h>
#include "../engine/Round.h"

#include <stdexcept>

// MockBreaker always proposes the same Code
class MockBreaker : public Breaker {
public:
    Code getCode() {
        Color colors[COLORS_PER_CODE] = {red, red, red, red};
        return Code(colors);
    }
};

TEST(RoundTest, MasterWins) {

    // MockMaster always evaluates with no blacks and no whites
    class MockMaster : public Master {
    public:
        Key getKey(const Code &code) {
            return Key(0, 0);
        }
    };

    MockMaster master = MockMaster();
    MockBreaker breaker = MockBreaker();
    Round round = Round(master, breaker);

    bool breakerWins = round.play();

    // Master wins after 12 rounds
    ASSERT_FALSE(breakerWins);
    ASSERT_EQ(MAX_TURNS_PER_ROUND - 1, round.getTurn());
}

TEST(RoundTest, BreakerWins) {

    // MockMaster always evaluates with 4 blacks
    class MockMaster : public Master {
    public:
        Key getKey(const Code &code) {
            return Key(4, 0);
        }
    };

    MockMaster master = MockMaster();
    MockBreaker breaker = MockBreaker();
    Round round = Round(master, breaker);

    bool breakerWins = round.play();

    // Breaker wins after 1 round
    ASSERT_TRUE(breakerWins);
    ASSERT_EQ(0, round.getTurn());
}

TEST(RoundTest, MasterCheats) {

    // MockMaster evaluates based on turn
    class MockMaster : public Master {
    public:
        Key getKey(const Code &code) {
            switch (round_->getTurn()) {
                case 0:
                    return Key(0, 0);
                case 1:
                    return Key(0, 1);
                default:
                    throw std::runtime_error("invalid flow");
            }
        }
    };

    MockMaster master = MockMaster();
    MockBreaker breaker = MockBreaker();
    Round round = Round(master, breaker);

    // No exception while playing round
    bool breakerWins;
    ASSERT_NO_THROW(breakerWins = round.play());

    // Breaker wins after 2 turns
    ASSERT_TRUE(breakerWins);
    ASSERT_EQ(1, round.getTurn());
}
