#ifndef MASTERMIND_HONESTMASTER_H
#define MASTERMIND_HONESTMASTER_H

#include "Master.h"

/**
 * A HonestMaster is a honest implementation of the abstract class Master.
 * It stores a secret Code provided at instantiation, and estimates the
 * Key associated to each Code accurately.
 */
class HonestMaster : public Master {

private:

    const Code &code_;

public:

    /**
     * Constructor.
     *
     * @param code The secret Code.
     */
    HonestMaster(const Code &code);

    Key getKey(const Code &code);

};

#endif //MASTERMIND_HONESTMASTER_H
