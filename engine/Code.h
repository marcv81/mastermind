#ifndef MASTERMIND_CODE_H
#define MASTERMIND_CODE_H

/** @file */

#include "Key.h"
#include <iostream>

/** Number of enumerated colors. */
#define COLORS_COUNT 6

/** Number of colors in each Code. */
#define COLORS_PER_CODE 4

/** Total number of all possible Code%s. */
#define CODES_COUNT (6 * 6 * 6 * 6)

/** Enumeration of all the colors. */
typedef enum {
    red,
    yellow,
    blue,
    orange,
    green,
    purple
} Color;

/**
 * A Code is a combination of COLORS_PER_CODE colors that the Master
 * holds secret and the Breaker tries to discover during a Round.
 */
class Code {

private:

    Color colors_[COLORS_PER_CODE];

public:

    /**
     * Constructor.
     *
     * @param codeIndex Code index in [0..CODES_COUNT-1].
     * @exception std::out_of_range if codeIndex is out of range.
     */
    Code(int codeIndex);

    /**
     * Constructor.
     *
     * @param colors Array of colors.
     * @exception std::out_of_range if any color is invalid.
     */
    Code(Color colors[COLORS_PER_CODE]);

    bool operator==(const Code &other) const;

    bool operator!=(const Code &other) const;

    /**
     * Get the color at a specified index.
     *
     * @param colorIndex Index in [0..COLORS_PER_CODE-1].
     * @return Color at the specified index.
     * @exception std::out_of_range if colorIndex is out of range.
     */
    Color getColor(int colorIndex) const;

    /**
     * Compare two Code%s.
     *
     * @param other Code to compare this Code to.
     * @return Key describing the commonalities between the two Code%s.
     */
    Key compare(const Code &other) const;
};

std::ostream &operator<<(std::ostream &stream, const Code &code);

#endif //MASTERMIND_CODE_H
