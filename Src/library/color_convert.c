#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "color.h"

/*  The following is a table of color maps and their structure.

	struct c_val
	  {
	   float red;	// percent red to be used.		//
	   float green;	// percent green to be used.		//
	   float blue;	// percent blue to be used.		//
	  };
	struct color_table
	  {
	   char name[17];	// name of the colormap		//
	   struct c_val cval[240];// the colormap		//
	   struct color_table *next; 	// pointer - next colormap	//
	  };
*/

struct color_table C_Tab={"default",
   100,100,100,   0,0,0,  
   60,80,100,  32,32,32,  86,100,100,  100,100,0,

   0,2.7451,100,   0,5.88235,100,   0,9.01961,100,   0,11.7647,100,   
   0,14.902,100,   0,18.0392,100,
   0,21.1765,100,   0,23.9216,100,   0,27.0588,100,   0,30.1961,100,   
   0,33.3333,100,   0,36.0784,100,
   0,39.2157,100,   0,42.3529,100,   0,45.098,100,   0,48.2353,100,   
   0,51.3725,100,   0,54.5098,100,
   0,57.2549,100,   0,60.3922,100,   0,63.5294,100,   0,66.6667,100,   
   0,69.4118,100,   0,72.549,100,
   0,75.6863,100,   0,78.4314,100,   0,81.5686,100,   0,84.7059,100,   
   0,87.8431,100,   0,90.5882,100,
   0,93.7255,100,   0,96.8627,100,   0,100,100,   0,100,96.8627,   
   0,100,93.7255,   0,100,90.5882,
   0,100,87.8431,   0,100,84.7059,   0,100,81.5686,   0,100,78.4314,   
   0,100,75.6863,   0,100,72.549,
   0,100,69.4118,   0,100,66.6667,   0,100,63.5294,   0,100,60.3922,   
   0,100,57.2549,   0,100,54.5098,
   0,100,51.3725,   0,100,48.2353,   0,100,45.098,   0,100,42.3529,   
   0,100,39.2157,   0,100,36.0784,
   0,100,33.3333,   0,100,30.1961,   0,100,27.0588,   0,100,23.9216,   
   0,100,21.1765,   0,100,18.0392,
   0,100,14.902,   0,100,11.7647,   0,100,9.01961,   0,100,5.88235,   
   0,100,2.7451,   0,100,0,
   2.7451,100,0,   5.88235,100,0,   9.01961,100,0,   11.7647,100,0,   
   14.902,100,0,   18.0392,100,0,
   21.1765,100,0,   23.9216,100,0,   27.0588,100,0,   30.1961,100,0,   
   33.3333,100,0,   36.0784,100,0,
   39.2157,100,0,   42.3529,100,0,   45.098,100,0,   48.2353,100,0,   
   51.3725,100,0,   54.5098,100,0,
   57.2549,100,0,   60.3922,100,0,   63.5294,100,0,   66.6667,100,0,   
   69.4118,100,0,   72.549,100,0,
   75.6863,100,0,   78.4314,100,0,   81.5686,100,0,   84.7059,100,0,   
   87.8431,100,0,   90.5882,100,0,
   93.7255,100,0,   96.8627,100,0,   100,100,0,   100,97.6471,0,   
   100,95.6863,0,   100,93.7255,0,
   100,91.7647,0,   100,89.8039,0,   100,87.8431,0,   100,85.4902,0,   
   100,83.5294,0,   100,81.5686,0,
   100,79.6078,0,   100,77.6471,0,   100,75.6863,0,   100,73.7255,0,   
   100,71.3726,0,   100,69.4118,0,
   100,67.451,0,   100,65.4902,0,   100,63.5294,0,   100,61.5686,0,   
   100,59.2157,0,   100,57.2549,0,
   100,55.2941,0,   100,53.3333,0,   100,51.3725,0,   100,49.4118,0,   
   100,47.451,0,   100,45.098,0,
   100,43.1373,0,   100,41.1765,0,   100,39.2157,0,   100,37.2549,0,   
   100,35.2941,0,   100,33.3333,0,
   100,32.1569,0,   100,30.9804,0,   100,30.1961,0,   100,29.0196,0,   
   100,28.2353,0,   100,27.0588,0,
   100,25.8824,0,   100,25.098,0,   100,23.9216,0,   100,23.1373,0,   
   100,21.9608,0,   100,21.1765,0,
   100,20,0,   100,18.8235,0,   100,18.0392,0,   100,16.8627,0,   
   100,16.0784,0,   100,14.902,0,
   100,14.1176,0,   100,12.9412,0,   100,11.7647,0,   100,10.9804,0,   
   100,9.80392,0,   100,9.01961,0,
   100,7.84314,0,   100,7.05882,0,   100,5.88235,0,   100,4.70588,0,   
   100,3.92157,0,   100,2.7451,0,
   100,1.96078,0,   100,0.784314,0,   100,0,0,   98.0392,0,0,   
   96.0784,0,0,   94.1176,0,0,
   92.1569,0,0,   90.1961,0,0,   88.6274,0,0,   86.6667,0,0,   84.7059,0,0,   
   82.7451,0,0,
   80.7843,0,0,   79.2157,0,0,   77.2549,0,0,   75.2941,0,0,   73.3333,0,0,   
   71.3726,0,0,
   69.4118,0,0,   67.8431,0,0,   65.8824,0,0,   63.9216,0,0,   61.9608,0,0,   
   60,0,0,
   58.4314,0,0,   56.4706,0,0,   54.5098,0,0,   52.549,0,0,   50.5882,0,0,   
   48.6275,0,0,
   47.0588,0,0,   45.098,0,0,   43.1373,0,0,   41.1765,0,0,   39.2157,0,0,   
   37.6471,0,0,
   38.4314,0,1.96078,   39.2157,0,3.92157,   40.3922,0,5.88235,   
   41.1765,0,7.84314,   42.3529,0,10.1961,   43.1373,0,12.1569,
   44.3137,0,14.1176,   45.098,0,16.0784,   46.2745,0,18.4314,   
   47.0588,0,20.3922,   48.2353,0,22.3529,   49.0196,0,24.3137,
   50.1961,0,26.2745,   50.9804,0,28.6275,   52.1569,0,30.5882,   
   52.9412,0,32.549,   54.1176,0,34.5098,   54.902,0,36.8627,
   55.6863,0,38.8235,   56.8627,0,40.7843,   57.6471,0,42.7451,   
   58.8235,0,44.7059,   59.6078,0,47.0588,   60.7843,0,49.0196,
   61.5686,0,50.9804,   62.7451,0,52.9412,   63.5294,0,55.2941,   
   64.7059,0,57.2549,   65.4902,0,59.2157,   66.6667,0,61.1765,
   67.451,0,63.1373,   68.6274,0,65.4902,   69.4118,0,67.451,   
   70.5882,0,69.4118,   71.3726,0,71.3726,   72.549,0,73.7255,
        NULL };

	main (argc,argv)
	  int argc;
	  char *argv[];
	  {
	   int i,j,red,green,blue,j16,k16,zero;
	   char name[21];
	   char filin[39];
	   char filout[39];

	   FILE *fpin,*fpout;

	   if (argc > 1)
	     {
	      if (strlen(argv[1]) > (size_t)0 && strlen(argv[1]) < (size_t)21)
		{
		 strcpy(name,argv[1]);
		 strcpy(filin,name);
		 strcat(filin,".cmp");
		 strcpy(filout,name);
		 strcat(filout,".scr");
		 if ( (fpin=fopen(filin,"r")) == NULL )
		   {
		    printf (" Cannot open input file - %s\n",filin);
		    return 0;
		   }
		 if ( (fpout=fopen(filout,"w")) == NULL )
		   {
		    printf (" Cannot open output file - %s\n",filout);
		    return 0;
		   }
	        }
	      else
		{
		 printf (" File name must be > 0 and < 21 characters\n");
		 return 0;
		}
	     }
	   else
	     {
	      printf (" Colormap name / Filename must be given.\n");
	      return 0;
	     }

	   for (i=0;i<256;i++)
	     {
	      fscanf (fpin,"%d %d %d %d %d %d %d",
				&j,&red,&green,&blue,&j16,&k16,&zero);
	      if (i > 31 && i < 253)
	        {
	         C_Tab.cval[i-15].red=(red/255.0)*100.0;
	         C_Tab.cval[i-15].green=(green/255.0)*100.0;
	         C_Tab.cval[i-15].blue=(blue/255.0)*100.0;
	        }
	     }
	    
	   C_Tab.cval[16].red=C_Tab.cval[17].red;
	   C_Tab.cval[16].green=C_Tab.cval[17].green;
	   C_Tab.cval[16].blue=C_Tab.cval[17].blue;

	   C_Tab.cval[238].red=C_Tab.cval[237].red;
	   C_Tab.cval[238].green=C_Tab.cval[237].green;
	   C_Tab.cval[238].blue=C_Tab.cval[237].blue;

	   C_Tab.cval[239].red=C_Tab.cval[237].red;
	   C_Tab.cval[239].green=C_Tab.cval[237].green;
	   C_Tab.cval[239].blue=C_Tab.cval[237].blue;

	   fprintf (fpout,"\nC_%s(\n  ",name);
	   for (i=0;i<240;i++)
	     {
	      fprintf (fpout,"%#5.1f,%#5.1f,%#5.1f",C_Tab.cval[i].red,
					C_Tab.cval[i].green,C_Tab.cval[i].blue);
	      if (i != 239) fprintf (fpout,", ");
	      if (i%4 == 3 && i != 239) fprintf (fpout,"\n  ");
	     }
	   fprintf (fpout,"  )\n");
	   return 0;
	  }
