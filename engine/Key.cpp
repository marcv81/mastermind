#include "Key.h"
#include <stdexcept>
#include "Code.h"

Key::Key(int blacks, int whites) : blacks_(blacks), whites_(whites) {

    if ((blacks < 0) || (whites < 0) || (blacks + whites > COLORS_PER_CODE)) {
        throw std::out_of_range("invalid blacks/whites combination");
    }
}

Key::Key(int keyIndex) {

    if ((keyIndex < 0) || (keyIndex >= KEYS_COUNT)) {
        throw std::out_of_range("invalid key index");
    }

    this->blacks_ = 0;
    this->whites_ = 0;

    int increment = COLORS_PER_CODE + 1;
    int threshold = increment;

    while (keyIndex >= threshold) {
        this->blacks_++;
        increment--;
        threshold += increment;
    }

    this->whites_ = keyIndex - threshold + increment;
}

int Key::toIndex() const {

    int increment = COLORS_PER_CODE + 1;
    int result = this->whites_;

    for (int i = 0; i < this->blacks_; i++) {
        result += increment;
        increment--;
    }

    return result;
}

bool Key::operator==(const Key &other) const {
    return (this->blacks_ == other.blacks_) && (this->whites_ == other.whites_);
}

bool Key::operator!=(const Key &other) const {
    return !(*this == other);
}

int Key::getBlacks() const {
    return this->blacks_;
}

int Key::getWhites() const {
    return this->whites_;
}

std::ostream &operator<<(std::ostream &stream, const Key &key) {
    for (int i = 0; i < key.getBlacks(); i++) {
        stream << "b";
    }
    for (int i = 0; i < key.getWhites(); i++) {
        stream << "w";
    }
    for (int i = 0; i < COLORS_PER_CODE - (key.getBlacks() + key.getWhites()); i++) {
        stream << "-";
    }
    return stream;
}
