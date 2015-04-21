#include "Code.h"
#include <stdexcept>

Code::Code(int codeIndex) {

    if ((codeIndex < 0) || (codeIndex >= CODES_COUNT)) {
        throw std::out_of_range("invalid code index");
    }

    for (int i = 0; i < COLORS_PER_CODE; i++) {
        div_t divResult;
        divResult = div(codeIndex, COLORS_COUNT);
        codeIndex = divResult.quot;
        this->colors_[i] = (Color) divResult.rem;
    }
}

Code::Code(Color colors[COLORS_PER_CODE]) {

    for (int i = 0; i < COLORS_PER_CODE; i++) {
        if ((colors[i] < 0) || (colors[i] >= COLORS_COUNT)) {
            throw std::out_of_range("invalid color");
        }
        this->colors_[i] = colors[i];
    }
}

bool Code::operator==(const Code &other) const {

    for (int i = 0; i < COLORS_PER_CODE; i++) {
        if (this->getColor(i) != other.getColor(i)) {
            return false;
        }
    }

    return true;
}

bool Code::operator!=(const Code &other) const {
    return !(*this == other);
}

Color Code::getColor(int colorIndex) const {

    if ((colorIndex < 0) || (colorIndex >= COLORS_PER_CODE)) {
        throw std::out_of_range("invalid color index");
    }

    return this->colors_[colorIndex];
}

Key Code::compare(const Code &other) const {

    int blacks = 0;
    int whites = 0;

    bool alreadyUsedThis[COLORS_PER_CODE] = {};
    bool alreadyUsedOther[COLORS_PER_CODE] = {};

    // Calculate number of blacks
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        if (this->getColor(i) == other.getColor(i)) {
            alreadyUsedThis[i] = true;
            alreadyUsedOther[i] = true;
            blacks++;
        }
    }

    // Calculate number of whites
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        for (int j = 0; j < COLORS_PER_CODE; j++) {
            if (!alreadyUsedThis[i] && !alreadyUsedOther[j] && (this->getColor(i) == other.getColor(j))) {
                alreadyUsedThis[i] = true;
                alreadyUsedOther[j] = true;
                whites++;
            }
        }
    }

    return Key(blacks, whites);
}

std::ostream &operator<<(std::ostream &stream, const Code &code) {
    for (int i = 0; i < COLORS_PER_CODE; i++) {
        switch (code.getColor(i)) {
            case red:
                stream << "R";
                break;
            case yellow:
                stream << "Y";
                break;
            case blue:
                stream << "B";
                break;
            case orange:
                stream << "O";
                break;
            case green:
                stream << "G";
                break;
            case purple:
                stream << "P";
                break;
        }
    }
    return stream;
}
