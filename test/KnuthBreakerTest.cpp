#include <gtest/gtest.h>
#include "../engine/Round.h"
#include "../engine/HonestMaster.h"
#include "../engine/KnuthBreaker.h"

TEST(KnuthBreakerTest, Efficiency) {

    for (int i = 0; i < CODES_COUNT; i++) {

        Code code = Code(i);
        HonestMaster master = HonestMaster(code);
        KnuthBreaker breaker = KnuthBreaker();

        Round round = Round(master, breaker);
        bool breakerWins = round.play();

        // Breaker wins in less than 5 turns for every Code
        ASSERT_TRUE(breakerWins);
        ASSERT_TRUE(round.getTurn() <= 4);
    }
}
