#include "Tvar.h"
#include <iostream>
#include <cmath>
#include <stdexcept>


namespace {
    constexpr float PI = 3.14159265358979323846f;
}

// ---------- KRUH ----------
class Kruh_odvozena_z_tvaru : public Tvar {
public:
    explicit Kruh_odvozena_z_tvaru(float r) : radius(r) {
        if (r <= 0.0f)
            throw std::invalid_argument("Polomer musi byt > 0");
    }

    float obvod() const override { return 2.0f * PI * radius; }
    float obsah() const override { return PI * radius * radius; }
    std::string jmeno() const override { return "Kruh"; }

private:
    float radius;
};

// ---------- POLYGON ----------
class Polygon_odvozena_z_tvaru : public Tvar {
public:
    Polygon_odvozena_z_tvaru(int n, float a) : pocet_uhlu(n), delka_strany(a) {
        if (n < 3)
            throw std::invalid_argument("Pocet uhlu musi byt >= 3");
        if (a <= 0.0f)
            throw std::invalid_argument("Delka strany musi byt > 0");
    }

    float obvod() const override { return pocet_uhlu * delka_strany; }
    float obsah() const override {
        return (pocet_uhlu * delka_strany * delka_strany) /
               (4.0f * std::tan(PI / static_cast<float>(pocet_uhlu)));
    }
    std::string jmeno() const override { return "Polygon"; }

protected:
    int pocet_uhlu;
    float delka_strany;
};

// ---------- ČTVEREC ----------
class Ctverec : public Polygon_odvozena_z_tvaru {
public:
    explicit Ctverec(float a) : Polygon_odvozena_z_tvaru(4, a) {}
    std::string jmeno() const override { return "Ctverec"; }
};

// ---------- Přetížené funkce ukazTvary ----------

// 1) KRUH
void ukazTvary(float radius) {
    Kruh_odvozena_z_tvaru k(radius);
    std::cout << k.jmeno()
              << " | obvod = " << k.obvod()
              << " | obsah = " << k.obsah() << '\n';
}

// 2) POLYGON
void ukazTvary(int n, float a) {
    Polygon_odvozena_z_tvaru p(n, a);
    std::cout << p.jmeno() << " (n=" << n << ")"
              << " | obvod = " << p.obvod()
              << " | obsah = " << p.obsah() << '\n';
}

// 3) ČTVEREC – rozlišení pomocí tagu
enum class TvarTag { Ctverec };

void ukazTvary(TvarTag, float a) {
    Ctverec c(a);
    std::cout << c.jmeno()
              << " | obvod = " << c.obvod()
              << " | obsah = " << c.obsah() << '\n';
}
