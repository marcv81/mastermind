#include <gtest/gtest.h>
#include "../engine/Code.h"

TEST(CodeTest, ConstructorExceptions) {

    Color colors[COLORS_PER_CODE];
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        colors[i] = (Color) (i % COLORS_COUNT);
    }

    // No constructor exceptions when all colors are valid
    ASSERT_NO_THROW(Code code = Code(colors));

    // Constructor exception when a color is invalid
    colors[0] = (Color) -1;
    ASSERT_ANY_THROW(Code code = Code(colors));
    colors[0] = (Color) COLORS_COUNT;
    ASSERT_ANY_THROW(Code code = Code(colors));
}

TEST(CodeTest, IndexConstructorExceptions) {

    // No constructor exceptions when index in bounds
    for (int i = 0; i < CODES_COUNT; i++) {
        ASSERT_NO_THROW(Code code = Code(i));
    }

    // Constructor exception when index out of bounds
    ASSERT_ANY_THROW(Code(-1));
    ASSERT_ANY_THROW(Code(CODES_COUNT));
}

TEST(CodeTest, ColorConstructorGetColor) {

    Color colors[COLORS_PER_CODE] = {red, green, orange, blue};
    Code code = Code(colors);

    // getColor() returns the expected value
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        ASSERT_EQ(colors[i], code.getColor(i));
    }
}

TEST(CodeTest, GetColorExceptions) {

    Code code = Code(0);

    // No getColor() exception when index in bounds
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        ASSERT_NO_THROW(Color color = code.getColor(i));
    }

    // getColor() exceptions when index out of bounds
    ASSERT_ANY_THROW(Color color = code.getColor(-1));
    ASSERT_ANY_THROW(Color color = code.getColor(COLORS_PER_CODE));
}

TEST(CodeTest, IndexConstructor) {

    // Distinct indices produce distinct codes
    for (int i = 0; i < CODES_COUNT; i++) {
        for (int j = i + 1; j < CODES_COUNT; j++) {
            ASSERT_NE(Code(i), Code(j));
        }
    }
}

TEST(CodeTest, Compare) {

    Color colorsA[COLORS_PER_CODE] = {blue, purple, orange, yellow};
    Color colorsB[COLORS_PER_CODE] = {yellow, orange, orange, purple};

    Key key = Code(colorsA).compare(Code(colorsB));

    // Compare returns the expected Key
    ASSERT_EQ(1, key.getBlacks());
    ASSERT_EQ(2, key.getWhites());
}
