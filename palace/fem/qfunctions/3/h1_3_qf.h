// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef PALACE_LIBCEED_H1_3_QF_H
#define PALACE_LIBCEED_H1_3_QF_H

#include "../coeff/coeff_3_qf.h"

CEED_QFUNCTION(f_apply_h1_3)(void *__restrict__ ctx, CeedInt Q, const CeedScalar *const *in,
                             CeedScalar *const *out)
{
  const CeedScalar *attr = in[0], *wdetJ = in[0] + Q, *u = in[1];
  CeedScalar *v = out[0];

  CeedPragmaSIMD for (CeedInt i = 0; i < Q; i++)
  {
    CeedScalar coeff[9];
    CoeffUnpack3((const CeedIntScalar *)ctx, (CeedInt)attr[i], coeff);

    const CeedScalar u0 = u[i + Q * 0];
    const CeedScalar u1 = u[i + Q * 1];
    const CeedScalar u2 = u[i + Q * 2];
    v[i + Q * 0] = wdetJ[i] * (coeff[0] * u0 + coeff[3] * u1 + coeff[6] * u2);
    v[i + Q * 1] = wdetJ[i] * (coeff[1] * u0 + coeff[4] * u1 + coeff[7] * u2);
    v[i + Q * 2] = wdetJ[i] * (coeff[2] * u0 + coeff[5] * u1 + coeff[8] * u2);
  }
  return 0;
}

#endif  // PALACE_LIBCEED_H1_3_QF_H
