/***************************************************************************
 * PES Assignment : Blinkenlights
 * file   log.h
 * References: This code is from lecture slides
 ***************************************************************************/

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#ifdef DEBUG
#define LOG printf
#else
#define LOG(...)
#endif

#endif
