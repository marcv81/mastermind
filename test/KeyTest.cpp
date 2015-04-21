#include <gtest/gtest.h>
#include "../engine/Code.h"

TEST(KeyTest, ConstructorExceptions) {

    // No constructor exception when the number of blacks or whites
    // is positive and their sum does not exceed COLORS_PER_CODE
    for (int i = 0; i <= COLORS_PER_CODE; i++) {
        for (int j = 0; j <= COLORS_PER_CODE - i; j++) {
            ASSERT_NO_THROW(Key key = Key(i, j));
        }
    }

    // Constructor exceptions when the number of blacks or whites
    // is negative or their sum exceeds COLORS_PER_CODE
    ASSERT_ANY_THROW(Key key = Key(-1, 0));
    ASSERT_ANY_THROW(Key key = Key(0, -1));
    for (int i = 0; i <= COLORS_PER_CODE + 1; i++) {
        ASSERT_ANY_THROW(Key key = Key(i, COLORS_PER_CODE + 1 - i));
    }
}

TEST(KeyTest, IndexConstructorExceptions) {

    // No constructor exceptions when index is in bounds
    for (int i = 0; i < KEYS_COUNT; i++) {
        ASSERT_NO_THROW(Key key = Key(i));
    }

    // Constructor exception when index is out of bounds
    ASSERT_ANY_THROW(Key(-1));
    ASSERT_ANY_THROW(Key(KEYS_COUNT));
}

TEST(KeyTest, ToIndex) {

    // toIndex() return expected index
    for (int i = 0; i < KEYS_COUNT; i++) {
        Key key = Key(i);
        ASSERT_EQ(i, key.toIndex());
    }
}

TEST(KeyTest, IndexConstructor) {

    // Distinct indices produce distinct Keys
    for (int i = 0; i < KEYS_COUNT; i++) {
        for (int j = i + 1; j < KEYS_COUNT; j++) {
            ASSERT_NE(Key(i), Key(j));
        }
    }
}

TEST(KeyTest, GetBlacksGetWhites) {

    // getBlacks() and getWhites() return the expected values
    for (int i = 0; i <= COLORS_PER_CODE; i++) {
        for (int j = 0; j <= COLORS_PER_CODE - i; j++) {
            Key key = Key(i, j);
            ASSERT_EQ(i, key.getBlacks());
            ASSERT_EQ(j, key.getWhites());
        }
    }
}
