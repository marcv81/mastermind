#include "HonestMaster.h"

HonestMaster::HonestMaster(const Code &code) : code_(code) { }

Key HonestMaster::getKey(const Code &code) {
    return this->code_.compare(code);
}
