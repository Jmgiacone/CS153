/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#include "TwoDPackage.h"

float TwoDPackage::getCharge() const
{
  return m_length * m_width * TWODRATE;
}

string TwoDPackage::getFrom() const
{
    return m_from;
}

string TwoDPackage::getTo() const
{
    return m_to;
}
