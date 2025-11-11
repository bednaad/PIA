#pragma once
#include <string>


struct Tvar {
    virtual ~Tvar() = default;

    virtual float obvod() const = 0;
    virtual float obsah() const = 0;
    virtual std::string jmeno() const = 0;
};
