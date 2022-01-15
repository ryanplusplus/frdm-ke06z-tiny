/*******************************************************************************
*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*
****************************************************************************//*!
*
* @brief  Algorithm of PMSM Back Electromotive Force observer in rotating 
*         reference frame     
* 
*******************************************************************************/
#ifndef _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_
#define _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_

#if defined(__cplusplus) 
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gflib.h"
#include "AMCLIB_PMSMBemfObsrvDQ_A32.h"   
#include "GFLIB_AtanYXHw_F32.h"
    
/*******************************************************************************
* Macros 
*******************************************************************************/    
#define AMCLIB_PMSMBemfObsrvDQHw_F16_C(psIDQ, psUDQ, f16Speed, psCtrl)       \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FC(psIDQ, psUDQ, f16Speed, psCtrl)
#define AMCLIB_PMSMBemfObsrvDQHw_F16_Asm(psIDQ, psUDQ, f16Speed, psCtrl)     \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(psIDQ, psUDQ, f16Speed, psCtrl)

/*******************************************************************************
* Types
*******************************************************************************/

   
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FC(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                frac16_t f16Speed, 
                                                AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);

extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                  const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                  frac16_t f16Speed,
                                                  AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);
#if defined(__cplusplus) 
}
#endif

#endif /* _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_ */       
