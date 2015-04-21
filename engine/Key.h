#ifndef MASTERMIND_KEY_H
#define MASTERMIND_KEY_H

/** @file */

#include <iostream>

/** Total number of all possible Key%s. */
#define KEYS_COUNT (5 + 4 + 3 + 2 + 1)

/**
 * A Key is combination of blacks and whites which represents the commonalities
 * between two Code%s. The blacks indicate the number of common colors at the
 * same position in both Code%s. The whites indicate the number of common colors
 * which are at a different positions in each Code.
 */
class Key {

private:

    int blacks_;
    int whites_;

public:

    /**
     * Constructor.
     *
     * @param blacks, whites Number of blacks and whites.
     * @exception std::out_of_range if the number of blacks or whites
     * is negative, or if their sum exceeds COLORS_PER_CODE.
     */
    Key(int blacks, int whites);

    /**
     * Constructor.
     *
     * @param keyIndex Key index in [0..KEYS_COUNT-1].
     * @exception std::out_of_range if keyIndex is out of range.
     */
    Key(int keyIndex);

    /**
     * Convert a Key to an index.
     *
     * @return Key's index in [0..KEYS_COUNT-1].
     */
    int toIndex() const;

    bool operator==(const Key &other) const;

    bool operator!=(const Key &other) const;

    /** Get the number of backs. */
    int getBlacks() const;

    /** Get the number of whites. */
    int getWhites() const;
};

std::ostream &operator<<(std::ostream &stream, const Key &key);

#endif //MASTERMIND_KEY_H
