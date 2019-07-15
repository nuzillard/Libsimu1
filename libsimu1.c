/*
    file: Libsimu1/libsimu1.c
    
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

#include <math.h>
#include "libsimu1.h"

/* This is simply the multiplication of a matrix by a vector */
void matvec(Mat33 m, Vec3 v1, Vec3 v2)
{
	Vec3 tmp ;
	int i, j ;

	for(i=0 ; i<3 ; i++) {
		tmp[i] = 0 ;
		for(j=0 ; j<3 ; j++)
			tmp[i] += m[i][j] * v1[j] ;
	}
	for(i=0 ; i<3 ; i++) v2[i] = tmp[i] ;
}

/* See theory.pdf for the proof */
void matrot(Mat33 m, Vec3 v, double angle)
{
	double ca, ca1, sa, f ;
	int i, j ;

	ca = cos(angle) ;
	sa = sin(angle) ;
	ca1 = 1-ca ;
	for(i=0 ; i<3 ; i++) 
		m[i][i] = ca + ca1 * v[i] * v[i] ; 
	for(i=1 ; i<3 ; i++) for(j=0 ; j<i ; j++)
			m[i][j] = m[j][i] = ca1 * v[i] * v[j] ;
	for(i=1 ; i<3 ; i++) for(j=0 ; j<i ; j++) {
		f = v[3-i-j] * ((i-j-1) ? (-1) : 1) * sa ;
		m[i][j] += f ;
		m[j][i] -= f ;
	}
}

