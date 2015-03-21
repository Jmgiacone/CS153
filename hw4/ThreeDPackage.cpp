/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-1-14
 */

#include "ThreeDPackage.h"

float ThreeDPackage::getCharge() const
{
  return m_length * m_width * m_height * THREEDCONSTANT + m_weight * THREEDRATE;
}
