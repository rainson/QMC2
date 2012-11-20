/* 
 * File:   alphaHO.h
 * Author: jorgehog
 *
 * Created on 27. juni 2012, 13:17
 */

#ifndef ALPHAHO_H
#define ALPHAHO_H

class alphaHO : public BasisFunctions {
protected:

    double* k;
    double* k2;
    double* exp_factor;

    double H;
    double x2;
    double y2;

public:

    alphaHO(double* k, double* k2, double* exp_factor);

};

//START OF GENERATED FUNCTIONS



//END OF GENERATED FUNCTIONS

#endif	/* ALPHAHO_H */