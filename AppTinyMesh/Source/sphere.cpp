
#include "sphere.h"

Sphere::Sphere() {
    int divB = 24; 
    int divA = divB / 2;
    float A0, A1, B; // On definit les angles

    
    // for (int i = 0; i < divA; i++)
    // {
    //     A0 = -0.5 * M_PI + (float)i * M_PI / divA; //Angle actuelen i
    //     A1 = -0.5 * M_PI + (float)(i + 1) * M_PI / divA; // Angle suivant
    //     for (int j = 0; j <= divB; j++)
    //     {
    //         B = (float)(j) * 2.f * M_PI / divB;//Angle en j
    //         Sphere.texcoord(((cos(A0) * cos(B)+1)/2)/4 + 0.75, ((cos(A0) * sin(B) + 1)/2)/4);
    //         Sphere.normal(cos(A0) * cos(B), sin(A0), cos(A0) * sin(B));
    //         Sphere.vertex(cos(A0) * cos(B), sin(A0), cos(A0) * sin(B));

    //         Sphere.normal(cos(A1) * cos(B), sin(A1), cos(A1) * sin(B));
    //         Sphere.vertex(cos(A1) * cos(B), sin(A1), cos(A1) * sin(B));
    //     }
    //     Sphere.restart_strip();
    // }
}