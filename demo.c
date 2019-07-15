/*
    file: Libsimu1/demo.c
    
    Copyright (c) 2019, Jean-Marc Nuzillard 
    University of Reims Champagne-Ardenne, CNRS.
    All rights reserved.

    Redistribution and use in source and binary forms, 
    with or without modification, are permitted provided that the following
    conditions are met:

    - Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
    BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
    OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <math.h>
#include "libsimu1.h"

/* Prints vector coordinates */
void printvec(Vec3 v)
{
	printf("(%.1f %.1f %.1f)", v[0], v[1], v[2]) ;
}

int main()
{
/* rotation angle, in degrees */
	double angle = 120.0 ;

/* rotation axis, not normalized */
	Vec3 ax = {1.0, 1.0, 1.0} ;

/* rotation matrix */
	Mat33 r ;

/* initial vector, along the z axis */
	Vec3 v = {0.0, 0.0, 1.0} ;

	double norm ;
	int i ;

/* prints what the program does */
	printf("\nThe %.1f degrees rotation\naround the ", angle) ;
	printvec(ax) ;
	printf(" axis\ntransforms the ") ;
	printvec(v) ;
	printf(" vector\n") ;

/* rotation angle in radians */
	angle *= (M_PI / 180.0) ;

/* normalization of axis vector */
	norm = hypot(hypot(ax[0], ax[1]), ax[2]) ;
	for(i=0 ; i<3 ; i++) {
		ax[i] /= norm ;
	}

/* computes the rotation matrix */
	matrot(r, ax, angle) ;

/* applies it to vector v */
	matvec(r, v, v) ;

/* prints the result */
	printf("into the ") ;
	printvec(v) ;
	printf(" vector.\n\n") ;

	return 0 ;
}
