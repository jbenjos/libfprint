/*******************************************************************************

License: 
This software was developed at the National Institute of Standards and 
Technology (NIST) by employees of the Federal Government in the course 
of their official duties. Pursuant to title 17 Section 105 of the 
United States Code, this software is not subject to copyright protection 
and is in the public domain. NIST assumes no responsibility  whatsoever for 
its use by other parties, and makes no guarantees, expressed or implied, 
about its quality, reliability, or any other characteristic. 

This software has been determined to be outside the scope of the EAR
(see Part 734.3 of the EAR for exact details) as it has been created solely
by employees of the U.S. Government; it is freely distributed with no
licensing requirements; and it is considered public domain.  Therefore,
it is permissible to distribute this software as a free download from the
internet.

Disclaimer: 
This software was developed to promote biometric standards and biometric
technology testing for the Federal Government in accordance with the USA
PATRIOT Act and the Enhanced Border Security and Visa Entry Reform Act.
Specific hardware and software products identified in this software were used
in order to perform the software development.  In no case does such
identification imply recommendation or endorsement by the National Institute
of Standards and Technology, nor does it imply that the products and equipment
identified are necessarily the best available for the purpose.  

*******************************************************************************/


/************************************************************************/
/***********************************************************************
      LIBRARY: FING - NIST Fingerprint Systems Utilities

      FILE:           NFIQREAD.C
      IMPLEMENTATION: Michael D. Garris
      ALGORITHM:      Elham Tabassi
                      Charles L. Wilson
                      Craig I. Watson
      DATE:           09/09/2004

      Contains read routines for various files supporting
      NFIQ (NIST Fingerprint Image Quality)

***********************************************************************
               ROUTINES:
                        read_imgcls_file()
                        read_znorm_file()

***********************************************************************/

#include <ioutil.h>
#include <nfiq.h>

/***********************************************************************
************************************************************************
#cat: read_imgcls_file - Routine opens a column-formatted text file
#cat:                    parsing in the first column of filenames as a
#cat:                    list of strings and the second column of
#cat:                    target image qualities as a list of strings.

   Input:
      imgclsfilep - input file name to be read
   Output:
      oimglist    - allocated list of file names read
      oclslist    - allocated list of target image qualities read
      onum_ims    - number of images read
   Return Code:
      Zero        - successful completion
      Negative    - system error
************************************************************************/
int read_imgcls_file(char *imgclsfile, char ***oimglist, char ***oclslist,
                      int *onum_imgs)
{
   int ret, alloc_flag;

   alloc_flag = TRUE;
   ret = read_strstr_file(imgclsfile, oimglist, oclslist, onum_imgs,
                          alloc_flag);

   return(ret);
}

/***********************************************************************
************************************************************************
#cat: read_znorm_file - Routine opens a column-formatted text file
#cat:                   parsing in the first column of mean values as a
#cat:                   list of floats and the second column of stddev
#cat:                   values as a list of floats.

   Input:
      znormfile   - input file name to be read
   Output:
      znorm_means - preallocated list of mean values read
      znorm_stds  - preallocated list of stddev values read
      num_znorms  - allocated length of output vectors
   Return Code:
      Zero        - successful completion
      Negative    - system error
************************************************************************/
int read_znorm_file(char *znormfile,
         float *znorm_means, float *znorm_stds, const int num_znorms)
{
   int ret, tnum_znorms, alloc_flag;

   tnum_znorms = num_znorms;
   alloc_flag = FALSE;
   ret = read_fltflt_file(znormfile, &znorm_means, &znorm_stds, &tnum_znorms,
                          alloc_flag);
   return(ret);
}
