#ifndef MASTERMIND_ROUND_H
#define MASTERMIND_ROUND_H

/** @file */

#include "Master.h"
#include "Breaker.h"

/** Maximum number of turns in each Round. */
#define MAX_TURNS_PER_ROUND 12

/**
 * A Round represent an attempt from the Breaker to discover a Code held
 * secret by the Master in a maximum of MAX_TURNS_PER_ROUND turns.
 *
 * The Round maintains a list of remaining secret Code%s consistent with
 * the Key%s the Master provided. This is used to ensure the Master does
 * not cheat. The list is available to the Master and the Breaker if they
 * want to use it in their respective strategies.
 *
 * If Breaker finds the secret Code in a maximum of MAX_TURNS_PER_ROUND
 * turns, or if the Master is caught cheating, then the Breaker wins the
 * Round. Otherwise the Master wins the Round.
 */
class Round {

private:

    int turn_ = 0;

    Master &master_;
    Breaker &breaker_;

    bool discardedCodes_[CODES_COUNT] = {};

public:

    /** Constructor from Master and Breaker. */
    Round(Master &master, Breaker &breaker);

    /**
     * Play the Round.
     *
     * @return If the Breaker wins the Round. This happens
     * if the Breaker successfully discovers the secret Code
     * or if the Master is caught cheating.
     */
    bool play();

    /** Get the current turn. */
    int getTurn() const;

    /** Determine if a Code identified by its codeIndex has been discarded. */
    bool isDiscardedCode(int codeIndex) const;

    /** Get the total number of discarded Code%s. */
    int getDiscardedCodesCount() const;

};

#endif //MASTERMIND_ROUND_H
