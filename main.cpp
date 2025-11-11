#include "Tvar.h"
#include <iostream>

enum class TvarTag { Ctverec };
void ukazTvary(float radius);
void ukazTvary(int n, float a);
void ukazTvary(TvarTag, float a);

int main() {
    ukazTvary(3.0f);                   // Kruh: r = 3
    ukazTvary(6, 1.2f);                // Polygon: n = 6, a = 1.2
    ukazTvary(TvarTag::Ctverec, 2.0f); // Ctverec: a = 2
    return 0;
}
