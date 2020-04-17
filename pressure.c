/*
* Author: Tyler Zars, tzars2019@my.fit.edu
* Course: CSE 1001, Section 01 Fall 2019
* Project: pressure.c
* Take in a user altitude in meters and find the corresponding atmosphere pressures
*/

#include <stdio.h>
#include <math.h>

int main(void){
  double gasConstant = 8.314462618; /* R0 - Universal gas constant, measured in J/(mol * K) */
  double earthSurfaceGravAccel = 9.80665; /* g - Earth-surface gravitational acceleration, measured in m/(s^2) */
  double airMolarMass = 0.02896968; /* M - Molar mass of dry air, measured in kg/mol */
  double tempLapseRate = 0.00976; /* L - Temperature lapse rate, measured in K/m */
  double seaLevelStandardTemp = 288.16; /* T0 - Sea level standard temperature, measured in K */
  double seaLevelStandardPressure = 101325; /* P0 - Sea level standard atmospheric pressure, measured in Pa */
  double baseNum1, baseNum2, baseNum3;
  double inAltitude1, inAltitude2, inAltitude3;
  double pressurePA1, pressureMBAR1, pressureATM1;
  double pressurePA2, pressureMBAR2, pressureATM2;
  double pressurePA3, pressureMBAR3, pressureATM3;
  double exponent = ((earthSurfaceGravAccel * airMolarMass)/(gasConstant * tempLapseRate));


  /* Altitute 1: Scan & Calculations*/
  printf("Enter the first altitude in meters: ");
  scanf("%lf", &inAltitude1);
  // printf("%lf \n", inAltitude1); /*Test 1*/
  baseNum1 = (1-((tempLapseRate*inAltitude1)/(seaLevelStandardTemp)));
  pressurePA1 = seaLevelStandardPressure*pow(baseNum1, exponent);
  //printf("%.2lf \n", pressurePA1);
  pressureMBAR1 = pressurePA1 * 0.01;
  //printf("%.2lf \n", pressureMBAR1);
  pressureATM1 = (pressurePA1/(1.01325*pow(10.0, 5.0)));
  //printf("%.2lf \n", pressureATM1);


  /* Altitute 2: Scan & Calculations*/
  printf("Enter the second altitude in meters: ");
  scanf("%lf", &inAltitude2);
  // printf("%lf \n", inAltitude1); /*Test 1*/
  baseNum2 = (1-((tempLapseRate*inAltitude2)/(seaLevelStandardTemp)));
  pressurePA2 = seaLevelStandardPressure*pow(baseNum2, exponent);
  //printf("%.2lf \n", pressurePA2);
  pressureMBAR2 = pressurePA2 * 0.01;
  //printf("%.2lf \n", pressureMBAR2);
  pressureATM2 = (pressurePA2/(1.01325*pow(10.0, 5.0)));
  //printf("%.2lf \n", pressureATM2);


  /* Altitute 1: Scan & Calculations*/
  printf("Enter the third altitude in meters: ");
  scanf("%lf", &inAltitude3);
  printf("\n");
  // printf("%lf \n", inAltitude1); /*Test 1*/
  baseNum3 = (1-((tempLapseRate*inAltitude3)/(seaLevelStandardTemp)));
  pressurePA3 = seaLevelStandardPressure*pow(baseNum3, exponent);
  //printf("%.2lf \n", pressurePA3);
  pressureMBAR3 = pressurePA3 * 0.01;
  //printf("%.2lf \n", pressureMBAR3);
  pressureATM3 = (pressurePA3/(1.01325*pow(10.0, 5.0)));
  //printf("%.2lf \n", pressureATM3);

  /* Printing out all the JAZZ with a table width of 17 */
  printf("%17s%17s%17s%17s\n","Altitute (M)","Pressure (Pa)","Pressure (mbar)","Pressure (atm)");
  printf("%17.02lf%17.02lf%17.02lf%17.02lf\n",inAltitude1, pressurePA1, pressureMBAR1, pressureATM1);
  printf("%17.02lf%17.02lf%17.02lf%17.02lf\n",inAltitude2, pressurePA2, pressureMBAR2, pressureATM2);
  printf("%17.02lf%17.02lf%17.02lf%17.02lf\n",inAltitude3, pressurePA3, pressureMBAR3, pressureATM3);


  return 0;
}
