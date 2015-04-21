#ifndef MASTERMIND_KNUTHBREAKER_H
#define MASTERMIND_KNUTHBREAKER_H

#include "Breaker.h"

/**
 * A KnuthBreaker implements the abstract class Breaker using Knuth's
 * algorithm to discover the secret Code in a maximum of 5 turns.
 */
class KnuthBreaker : public Breaker {

public:

    /** Proposes Code%s according to Knuth's algorithm. */
    Code getCode();

};

#endif //MASTERMIND_KNUTHBREAKER_H
