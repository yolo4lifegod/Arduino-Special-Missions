/***********************************************************
 * Project: Special Mission 4: System of Equations solver  *
 * Robotics III. Doral Academy Preparatory School          *
 * This project solves a system of three equations with 3  * 
 * variables (x,y,z) and uses Linea Algebra techniques     *
 * Jose Del Valle. Robotics Instructor.                    *
 * Edited by Yash Saxena.                                  *
 * Go to lines 34 to 39 to edit matrix.                    *
 * ********************************************************/
 
// This project uses the library BasicLinearAlgebra.h developed by Tom Stewart (available in the file 3x3_Matrice_Solver)
// Named as BasicLinearAlgebra-master.zip

#include <BasicLinearAlgebra.h>
using namespace BLA;

#include <LiquidCrystal.h>

// Declaration of matrices below
BLA::Matrix<3,3> A; // Coefficient's matrix
BLA::Matrix<3> B; // Independent terms vector
BLA::Matrix<3,3> C; // Inverse Matrix
BLA::Matrix<3,1> D; // x,y,z solutions

// The solution's variables.
float X=0;
float Y=0;
float Z=0;
 
void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  
  // These are coefficient values
  A <<  -1,  1, 2,
         1, -1,-3,
        -1, -1,-2;
  // The numbers on the other side of the equation:
  B <<  -12,
         15,
         4;
  
  // Now find the Coefficient's matrix inverse 
  C = A.Inverse();  
  
  // Now, to finde the solution's vector, multiply C by the Independent terms' vector 
  D = C * B;
  
  // Now store the contents of the solution's vector into X, Y and Z variables.
  X=D(0,0);
  Y=D(1,0);
  Z=D(2,0);

  if(X == -0.00){
    X = 0;
  }
  if(Y == -0.00){
    Y = 0;
  }
  if(Z == -0.00){
    Z = 0;
  }
  
  // Print out the solution.
  Serial.print("X = ");
  Serial.println(X);
  Serial.print("Y = ");
  Serial.println(Y);
  Serial.print("Z = ");
  Serial.println(Z);
}

void loop() {
  // No code to loop
}
