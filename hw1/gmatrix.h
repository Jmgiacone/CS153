/* @file: gmatrix.h
 * Definition of class GMatrix
 * @C - Galaxy Express Softworks 
 * 
 * Version 14.1
 */

#ifndef GMATRIX_H
#define GMATRIX_H

#include <iostream>

/* _________________
  /                 \
  |  GMatrix  Class |
  \_________________/
   
    Purpose: Implements Gradient Matrix, as required by the Cerulian Curators
*/

// ---------------  Class GMatrix Declarations
class GMatrix
{ 
private:  
  int m_cols;                          // number of columns         
  int m_rows;                          // number of rows                  
  int** m_data;                        // 2D array to store Gradient Matrix


public:
  // Purpose: Constructs a Gradient Matrix
  // Preconditions:
  //     'c' and 'r' are greater than 0;
  //     's' and 'd' are greater than or equal to 0;
  // Postconditions: 
  //     m_cols and m_rows set to 'c', and 'r'; respectively. 
  //     m_data points to a dynamically allocated 2D array of [m_cols] by [m_rows]
  //     m_data[][] contains a gradient matrix with seed 's' and step 'd'.
  
  GMatrix(int c, int r, int s, int d);


  /* 
   * ---- Big 3 Member Functions ---*/

  // Purpose: Destructor
  // Postconditions: m_data[][] deallocated
  ~GMatrix();

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' GMatrix
  // Parameters: rhs, GMatrix to be copied
  // Returns: *this
  // Postconditions: *this == rhs
  const GMatrix& operator=(const GMatrix& rhs);

  // Purpose: Copy Constructor
  // Parameters: rhs - GMatrix to be copied
  // Postconditions:  *this == rhs
  GMatrix(const GMatrix& rhs);


  /* 
   * ----- Complex Accessor Operations ----- */
  
  // Purpose: prints the Gradient Matrix
  friend std::ostream& operator<< (std::ostream& out, 
                                   const GMatrix& gm);
};

// ---------------  Friend Function to Print
// Purpose: prints a GMatrix
std::ostream& operator<< (std::ostream& out, const GMatrix& gm);

#endif
