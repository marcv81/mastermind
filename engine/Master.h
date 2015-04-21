#ifndef MASTERMIND_MASTER_H
#define MASTERMIND_MASTER_H

#include "Code.h"

class Round;

/**
 * A Master represents the player who knows the secret Code that
 * the Breaker tries to discover during a Round. This abstract
 * class does not provide an implementation to evaluate the Key%s
 * associated to the proposed Code%s.
 */
class Master {

protected:

    Round *round_;

public:

    /**
     * Evaluates the Key associated to a proposed Code.
     *
     * @param code Proposed Code.
     * @returns Key describing the commonalities between the
     * secret Code and the proposed Code.
     */
    virtual Key getKey(const Code &code) = 0;

    /** Sets the Round. */
    void setRound(Round *round);

};

#endif //MASTERMIND_MASTER_H
