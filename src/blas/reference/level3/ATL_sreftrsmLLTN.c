/* ---------------------------------------------------------------------
 *
 * -- Automatically Tuned Linear Algebra Software (ATLAS)
 *    (C) Copyright 2000 All Rights Reserved
 *
 * -- ATLAS routine -- Version 3.9.24 -- December 25, 2000
 *
 * Author         : Antoine P. Petitet
 * Originally developed at the University of Tennessee,
 * Innovative Computing Laboratory, Knoxville TN, 37996-1301, USA.
 *
 * ---------------------------------------------------------------------
 *
 * -- Copyright notice and Licensing terms:
 *
 *  Redistribution  and  use in  source and binary forms, with or without
 *  modification, are  permitted provided  that the following  conditions
 *  are met:
 *
 * 1. Redistributions  of  source  code  must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce  the above copyright
 *    notice,  this list of conditions, and the  following disclaimer in
 *    the documentation and/or other materials provided with the distri-
 *    bution.
 * 3. The name of the University,  the ATLAS group,  or the names of its
 *    contributors  may not be used to endorse or promote products deri-
 *    ved from this software without specific written permission.
 *
 * -- Disclaimer:
 *
 * THIS  SOFTWARE  IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE UNIVERSITY
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO,  PROCUREMENT  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEO-
 * RY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (IN-
 * CLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ---------------------------------------------------------------------
 */
/*
 * Include files
 */
#include "atlas_refmisc.h"
#include "atlas_reflvl3.h"
#include "atlas_reflevel3.h"

void ATL_sreftrsmLLTN
(
   const int                  M,
   const int                  N,
   const float                ALPHA,
   const float                * A,
   const int                  LDA,
   float                      * B,
   const int                  LDB
)
{
/*
 * Purpose
 * =======
 *
 * ATL_sreftrsmLLTN( ... )
 *
 * <=>
 *
 * ATL_sreftrsm
 * ( AtlasLeft, AtlasLower, AtlasTrans, AtlasNonUnit, ... )
 *
 * See ATL_sreftrsm for details.
 *
 * ---------------------------------------------------------------------
 */
/*
 * .. Local Variables ..
 */
   register float             t0;
   int                        i, iaki, ibij, ibkj, j, jai, jbj, k;
/* ..
 * .. Executable Statements ..
 *
 */
   for( j = 0, jbj = 0; j < N; j++, jbj += LDB )
   {
      for( i = M-1,     jai  = (M-1)*LDA, ibij  = M-1+jbj;
           i >= 0; i--, jai -= LDA,       ibij -= 1 )
      {
         t0 = ALPHA * B[ibij];
         for( k = i+1,    iaki  = i+1+jai, ibkj  = i+1+jbj;
              k < M; k++, iaki += 1,       ibkj += 1 )
         { t0 -= A[iaki] * B[ibkj]; }
         t0 /= A[i+jai];
         B[ibij] = t0;
      }
   }
/*
 * End of ATL_sreftrsmLLTN
 */
}
