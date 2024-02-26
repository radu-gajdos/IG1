#include <cassert>
#include "L2_Gajdos_Radu_Problem0_length.h"


void test_alle()
{

    // constructor/deklaration
    Length laenge1(3, "m");

    // get_value
    assert(laenge1.get_value() == 3);

    // get_unit
    assert(laenge1.get_unit() == "m");

    // add
    Length laenge2(1, "m");

    Length laengeadd = laenge1.add(laenge2);
    assert(laengeadd.get_value() == 4);
    assert(laengeadd.get_unit() == "m");

    // +

    Length laengeplus = laenge1 + laenge2;
    assert(laengeplus.get_value() == 4);
    assert(laengeplus.get_unit() == "m");

    // sub

    Length laengesub = laenge1.subtract(laenge2);
    assert(laengesub.get_value() == 2);
    assert(laengesub.get_unit() == "m");

    // -

    Length laengeminus = laenge1 + laenge2;
    assert(laengeminus.get_value() == 4);
    assert(laengeminus.get_unit() == "m");

    // scale

    Length laengeskalar = laenge1.scale(2);
    assert(laengeskalar.get_value() == 6);
    assert(laengeskalar.get_unit() == "m");

    // *

    Length laengemal = laenge1*2;
    assert(laengemal.get_value() == 6);
    assert(laengemal.get_unit() == "m");

    // divide

    Length laengedivide = laenge1.divide(2);
    assert(laengedivide.get_value() == 1.5);
    assert(laengedivide.get_unit() == "m");

    // /

    Length laengeslash = laenge1/2;
    assert(laengeslash.get_value() == 1.5);
    assert(laengeslash.get_unit() == "m");

    // text
    assert(laenge1.text() == "3.000000m");

    // compare
    Length laenge3 = laenge1;
    assert(laenge1.compare(laenge2) == 1);
    assert(laenge2.compare(laenge1) == -1);
    assert(laenge3.compare(laenge1) == 0);

    // konversion

    Length laengekonv(1, "km");
    laengekonv.convert("m");
    assert(laengekonv.get_value()==1000);
    laengekonv.convert("km");
    assert(laengekonv.get_value()==1);
}
