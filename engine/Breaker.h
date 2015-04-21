#ifndef MASTERMIND_BREAKER_H
#define MASTERMIND_BREAKER_H

#include "Code.h"

class Round;

/**
 * A Breaker represents the player trying to discover a Code held
 * secret by the Master during a Round. This abstract class does
 * not provide an implementation to propose Code%s.
 */
class Breaker {

protected:

    Round *round_;

public:

    /** Proposes a Code. */
    virtual Code getCode() = 0;

    /** Sets the Round. */
    void setRound(Round *round);

};

#endif //MASTERMIND_BREAKER_H
