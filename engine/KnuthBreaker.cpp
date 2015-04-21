#include "KnuthBreaker.h"
#include "Round.h"

Code KnuthBreaker::getCode() {

    // First turn
    if (round_->getTurn() == 0) {
        Color colors[COLORS_PER_CODE] = {red, red, yellow, yellow};
        return Code(colors);
    }

    // Non-discarded codes count
    int availableCodesCount = CODES_COUNT - round_->getDiscardedCodesCount();

    // Score for each code
    int codeScores[CODES_COUNT];

    // Iterate over all codes
    for (int i = 0; i < CODES_COUNT; i++) {
        Code code = Code(i);

        // Score for each key
        int keyScores[KEYS_COUNT] = {};

        // Iterate over non-discarded codes
        for (int j = 0; j < CODES_COUNT; j++) {
            if (round_->isDiscardedCode(j)) {
                continue;
            }

            // Count non-discarded codes per key
            Key key = code.compare(Code(j));
            keyScores[key.toIndex()]++;
        }

        // Find highest key score
        int topKeyScore = 0;
        for (int j = 0; j < KEYS_COUNT; j++) {
            if (keyScores[j] > topKeyScore) {
                topKeyScore = keyScores[j];
            }
        }

        // Calculate code score
        codeScores[i] = availableCodesCount - topKeyScore;
    }

    // Find first code with highest score
    int codeIndex = 0;
    int topCodeScore = 0;
    for (int i = 0; i < CODES_COUNT; i++) {
        if (codeScores[i] > topCodeScore) {
            codeIndex = i;
            topCodeScore = codeScores[i];
        }
    }

    // If first code with highest score has been discarded
    // Then find first non-discarded code with same score (if any)
    if (round_->isDiscardedCode(codeIndex)) {
        for (int i = 0; i < CODES_COUNT; i++) {
            if (!round_->isDiscardedCode(i) && (codeScores[i] == topCodeScore)) {
                codeIndex = i;
                break;
            }
        }
    }

    return Code(codeIndex);
}
