#include "Round.h"

Round::Round(Master &master, Breaker &breaker) : master_(master), breaker_(breaker) {
    master.setRound(this);
    breaker.setRound(this);
}

bool Round::play() {

    while (true) {

        Code code = breaker_.getCode();
        Key key = master_.getKey(code);

        std::cout << code << " " << key << " " << turn_ + 1 << std::endl;

        // Discard possible codes based on key
        for (int i = 0; i < CODES_COUNT; i++) {
            if (!discardedCodes_[i] && (key != code.compare(Code(i)))) {
                discardedCodes_[i] = true;
            }
        }

        // Breaker finds the code
        if (key.getBlacks() == 4) {
            std::cout << "Breaker wins!" << std::endl;
            return true;
        }

        // Master gives key which discards all possible codes
        if (getDiscardedCodesCount() == CODES_COUNT) {
            std::cout << "Master cheated, breaker wins!" << std::endl;
            return true;
        }

        // Final turn has been played
        if (turn_ >= MAX_TURNS_PER_ROUND - 1) {
            std::cout << "Master wins!" << std::endl;
            return false;
        }

        turn_++;
    }
}

int Round::getTurn() const {
    return turn_;
}

bool Round::isDiscardedCode(int codeIndex) const {
    return discardedCodes_[codeIndex];
}

int Round::getDiscardedCodesCount() const {

    int counter = 0;

    for (int i = 0; i < CODES_COUNT; i++) {
        if (discardedCodes_[i]) {
            counter++;
        }
    }

    return counter;
}
