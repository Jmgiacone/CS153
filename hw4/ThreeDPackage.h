/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#ifndef THREEDPACKAGE_H
#define THREEDPACKAGE_H
#include "TwoDPackage.h"

const float THREEDRATE = 2.71, THREEDCONSTANT = .02;

class ThreeDPackage : public TwoDPackage
{
protected:
    float m_height;
public:
    ThreeDPackage(string from, string to, float l, float w, float h, float weight) : TwoDPackage(from, to, l, w, weight), m_height(h){}

    // Purpose: Returns the charge of a package.
    virtual float getCharge() const;
};
#endif // 3DPACKAGE_H
