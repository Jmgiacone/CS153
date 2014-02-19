/*
 * Name: GIACONE, JORDAN
 * Date: 2-6-14
 * Class and Section: CS153, Section C
*/

#include "gmatrix.h"

GMatrix::GMatrix(int c, int r, int s, int d)
{
  m_cols = c;
  m_rows = r;
  int seed = s;
  m_data = new int*[m_rows];

  for(int i = 0; i < m_rows; i++)
  {
    m_data[i] = new int[m_cols];
  }
 
  for(int i = 0; i < m_rows; i++)
  {
    seed = s + (d * i);
    for(int j = 0; j < m_cols; j++)
    {
      m_data[i][j] = seed + (d * j);
    }
  } 
}

GMatrix::~GMatrix()
{
  for(int i = 0; i < m_rows; i++)
  {
    delete [] m_data[i];
  }

  delete [] m_data;
}

const GMatrix& GMatrix::operator = (const GMatrix& rhs)
{
  if(this != &rhs)
  {
    for(int i = 0; i < m_rows; i++)
    {
      delete [] m_data[i];
    }

    delete [] m_data;

    m_rows = rhs.m_rows;
    m_cols = rhs.m_cols;

    m_data = new int*[m_rows];

    for(int i = 0; i < m_rows; i++)
    {
      m_data[i] = new int[m_cols];
    }

    for(int i = 0; i < m_rows; i++)
    {
      for(int j = 0; j < m_cols; j++)
      {
        m_data[i][j] = rhs.m_data[i][j];
      }
    }
  }

  return *this;
}

GMatrix::GMatrix(const GMatrix& rhs)
{
  //Make sure the grid is initialized
  m_rows = m_cols = 1;
  m_data = new int*[m_rows];
  m_data[0] = new int[m_cols];

  *this = rhs; 
}

std::ostream& operator << (std::ostream& out, const GMatrix& gm)
{
  for(int i = 0; i < gm.m_rows; i++)
  {
    for(int j = 0; j < gm.m_cols; j++)
    {
      out << (gm.m_data[i][j] < 10 ? "0" : "") << gm.m_data[i][j] << " ";
    }

    out << std::endl;
  }  

  return out;
}
