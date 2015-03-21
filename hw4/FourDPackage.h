/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#ifndef FOURDPACKAGE_H
#define FOURDPACKAGE_H
#include "ThreeDPackage.h"

const float FOURDRATE = 3.14, EXTRA_DIMENSIONAL_HANDLING = 42.42, FOURDCONSTANT = .01;

class FourDPackage : public ThreeDPackage
{
protected:
    float m_time; //Apparently the 4th dimension...
public:
    FourDPackage(string from, string to, float l, float w, float h, float t, float weight) : ThreeDPackage(from, to, l, w, h, weight), m_time(t) {}

    // Purpose: Returns the charge of a package.
    virtual float getCharge() const;
};
#endif // 4DPACKAGE_H
