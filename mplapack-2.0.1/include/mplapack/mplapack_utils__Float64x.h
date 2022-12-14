/*
 * Copyright (c) 2021
 *	Nakata, Maho
 * 	All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef _MPLAPACK_UTILS__FLOAT64X_H_
#define _MPLAPACK_UTILS__FLOAT64X_H_

typedef __float80 _Float64x;
#define ___MPLAPACK__FLOAT64X_IS_LONGDOUBLE___

#include <math.h>

#if defined ___MPLAPACK__FLOAT64X_IS_LONGDOUBLE___

// Intel C/C++ compilers currently only supports long double as extended doule (aka FP80)
// and following workaround works
#if defined(__INTEL_COMPILER)
    typedef long double _Float64x;
#endif

#if defined ___MPLAPACK_INTERNAL___
#define FLOAT64X_FORMAT "%+25.21Le"
#define FLOAT64X_SHORT_FORMAT "%+20.16Le"

#if !defined __MPLAPACK_BUFLEN__
#define __MPLAPACK_BUFLEN__ 1024
#endif

inline void printnum(_Float64x rtmp) { printf(FLOAT64X_FORMAT, rtmp); }
inline void printnum(std::complex<_Float64x> ctmp) { printf(FLOAT64X_FORMAT FLOAT64X_FORMAT "i", ctmp.real(), ctmp.imag()); }

inline void printnum_short(_Float64x rtmp) { printf(FLOAT64X_SHORT_FORMAT, rtmp); }
inline void printnum_short(std::complex<_Float64x> ctmp) { printf(FLOAT64X_SHORT_FORMAT FLOAT64X_SHORT_FORMAT "i", ctmp.real(), ctmp.imag()); }

inline void sprintnum(char *buf, _Float64x rtmp) { snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT64X_FORMAT, rtmp); }
inline void sprintnum(char *buf, std::complex<_Float64x> ctmp) { snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT64X_FORMAT FLOAT64X_FORMAT "i", ctmp.real(), ctmp.imag()); }

inline void sprintnum_short(char *buf, _Float64x rtmp) { snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT64X_SHORT_FORMAT, rtmp); }
inline void sprintnum_short(char *buf, std::complex<_Float64x> ctmp) { snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT64X_SHORT_FORMAT FLOAT64X_SHORT_FORMAT "i", ctmp.real(), ctmp.imag()); }
#endif

inline _Float64x pow2(const _Float64x &a) { return a * a; }

#ifdef __cplusplus
extern "C" {
#endif
#include <complex.h>
#include <complex>
#ifdef __cplusplus
}
#endif

// implementation of sign transfer function.
inline _Float64x sign(const _Float64x &a, const _Float64x &b) {
    _Float64x mtmp;
    mtmp = std::abs(a);
    if (b < 0.0) {
        mtmp = -mtmp;
    }
    return mtmp;
}

inline double cast2double(_Float64x a) { return (double)a; }

inline long nint(_Float64x a) {
    long i;
    _Float64x tmp;
    a = a + 0.5;
    tmp = floor(a);
    i = (long)tmp;
    return i;
}

inline _Float64x castREAL__Float64x(mplapackint n) {
    _Float64x ret = n;
    return ret;
}

inline mplapackint castINTEGER__Float64x(_Float64x a) {
    mplapackint i = a;
    return i;
}

inline _Float64x pi(_Float64x dummy) {
#if defined __APPLE__ // __MATH_LONG_DOUBLE_CONSTANTS looks broken
    return 0xc.90fdaa22168c235p-2L;
#elif defined __MINGW32__
    return 0xc.90fdaa22168c235p-2L;
#else
    return M_PIl;
#endif
}

#endif

#if defined ___MPLAPACK__FLOAT64X_BROKEN___
inline _Float64x abs(const std::complex<_Float64x> &a) { return sqrtl(a.real() * a.real() + a.imag() * a.imag()); }

inline std::complex<_Float64x> sqrt(const std::complex<_Float64x> a) {
    _Float64x _Complex b, tmp;
    std::complex<_Float64x> c;
    __real__(b) = (a.real());
    __imag__(b) = (a.imag());
    tmp = csqrtl(b);
    c.real(__real__(tmp));
    c.imag(__imag__(tmp));
    return c;
}

inline std::complex<_Float64x> sin(const std::complex<_Float64x> a) {
    _Float64x _Complex b, tmp;
    std::complex<_Float64x> c;
    __real__(b) = (a.real());
    __imag__(b) = (a.imag());
    tmp = csinl(b);
    c.real(__real__(tmp));
    c.imag(__imag__(tmp));
    return c;
}

inline std::complex<_Float64x> cos(const std::complex<_Float64x> a) {
    _Float64x _Complex b, tmp;
    std::complex<_Float64x> c;
    __real__(b) = (a.real());
    __imag__(b) = (a.imag());
    tmp = ccosl(b);
    c.real(__real__(tmp));
    c.imag(__imag__(tmp));
    return c;
}

inline std::complex<_Float64x> exp(const std::complex<_Float64x> &a) {
    _Float64x _Complex b, tmp;
    std::complex<_Float64x> c;
    __real__(b) = (a.real());
    __imag__(b) = (a.imag());
    tmp = cexpl(b);
    c.real(__real__(tmp));
    c.imag(__imag__(tmp));
    return c;
}

inline std::complex<_Float64x> log(const std::complex<_Float64x> &a) {
    _Float64x _Complex b, tmp;
    std::complex<_Float64x> c;
    __real__(b) = (a.real());
    __imag__(b) = (a.imag());
    tmp = clogl(b);
    c.real(__real__(tmp));
    c.imag(__imag__(tmp));
    return c;
}
#endif //___MPLAPACK__FLOAT64X_BROKEN___

#endif
