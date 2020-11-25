/*
 * lab3.cpp
 *
 *  Created on: Feb. 25, 2020
 *      Author: goutham
 */

#include<stdio.h>
#define MAX 100

void
printMat (float a[MAX][MAX], int m)
{
  printf ("The Matrix is : \n");
  for (int e = 0; e < m; e++)
    {
      for (int f = 0; f < m + 1; f++)
	{
	  printf ("%f ", a[e][f]);
	}
      printf ("\n\n\n");
    }
}

int
main ()
{
  int m;
  float op[MAX];
  float eq[MAX][MAX];
  float fact;
  printf ("Enter the no. of equations & variable : ");
  scanf ("%d", &m);
  for (int e = 0; e < m; e++)
    {
      for (int f = 0; f < m + 1; f++)
	{
	  printf ("Enter the eq[%d][%d] element : ", e, f);
	  scanf ("%f", &eq[e][f]);
	}
    }
  printf ("Inputted matrix\n");
  printMat (eq, m);
  for (int e = 1; e < m; e++)
    {
      int z = 0;
      for (int f = 0; f < e; f++)
	{
	  fact = eq[e][f] / eq[z][f];
	  for (int k = 0; k < m + 1; k++)
	    {
	      eq[e][k] = eq[e][k] - (fact * eq[z][k]);
	    }
	  z++;
	}
    }
  printf ("Value after Row Transformation : \n");
  printMat (eq, m);
  op[m - 1] = eq[m - 1][m] / eq[m - 1][m - 1];
  for (int e = m - 2; e >= 0; e--)
    {
      float summation = 0;
      for (int f = m - 1; f > e; f--)
	summation = summation + (eq[e][f] * op[f]);
      op[e] = (eq[e][m] - summation) / eq[e][e];
    }
  for (int e = 0; e < m; e++)
    printf ("Value of x%d is %f\n", e + 1, op[e]);
  return 0;
}

