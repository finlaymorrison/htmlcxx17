/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This file is part of htmlcxx -- A simple non-validating css1 and html parser
 * written in C++.
 *
 * htmlcxx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * htmlcxx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with htmlcxx.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright 2005-2010 Davi de Castro Reis and Robson Braga Araújo
 * Copyright 2011 David Hoerl
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef DEBUGP
#undef DEBUGP
#endif

#ifdef __cplusplus
#include <cstdio>
#if defined(WIN32) && !defined(__MINGW32__)
#include <cstring>
#endif
#else
#include <stdio.h>
#if defined(WIN32) && !defined(__MINGW32__)
#include <string.h>
#endif
#endif

#if defined(WIN32) && !defined(__MINGW32__)
#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdarg.h>
inline void debugprintf(const char *format, ...)
{
    va_list ap;
	char *f = NULL;
	const char *p="%s:%d ";
	size_t plen = strlen(p);
    va_start(ap, format);
	f = (char *)malloc(plen + strlen(format) + 1);
	if (!f) return;
	memcpy(f, p, plen);
	memcpy(f + plen, format, strlen(format) + 1);
    vfprintf(stderr, f, ap);
    va_end(ap);
	free(f);
}
inline void dummyprintf(const char *format, ...)
{}
#endif
#endif

#ifdef EN_DEBUG_HTMLCXX
#if defined(WIN32) && !defined(__MINGW32__)
#define DEBUGP debugprintf
#else
#define DEBUGP(args...) do { fprintf(stderr, "%s:%d ", __FILE__, __LINE__); fprintf(stderr, ## args); } while(0)
#endif
#else
#if defined(WIN32) && !defined(__MINGW32__)
#define DEBUGP dummyprintf
#else
#define DEBUGP(args...)
#endif
#endif
