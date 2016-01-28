/*
 * Log.h
 *
 *  Created on: 9 Oct 2015
 *      Author: mickael
 */

#ifndef LOG_H_
#define LOG_H_

#include <ostream>
#include <iostream>

enum LL_LOG{
  LL_NONE,
  LL_CRITIC,
  LL_ERROR,
  LL_WARNING,
  LL_INFO,
  LL_DEBUG,
  LL_VERBOSE
};

#ifdef VERBOSE
#define LogV(...) do { if (log_level>=LL_VERBOSE) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogD(...) do { if (log_level>=LL_DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogI(...) do { if (log_level>=LL_INFO) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogW(...) do { if (log_level>=LL_WARNING) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogE(...) do { if (log_level>=LL_ERROR) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogC(...) do { if (log_level>=LL_CRITIC) fprintf(stderr, __VA_ARGS__); } while (0)
extern LL_LOG log_level;
#elif RELEASE
#define LogV(...)
#define LogD(...)
#define LogI(...) do { if (log_level>=LL_INFO) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogW(...) do { if (log_level>=LL_WARNING) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogE(...) do { if (log_level>=LL_ERROR) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogC(...) do { if (log_level>=LL_CRITIC) fprintf(stderr, __VA_ARGS__); } while (0)
extern LL_LOG log_level;
#else
#define LogV(...)
#define LogD(...) do { if (log_level>=LL_DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogI(...) do { if (log_level>=LL_INFO) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogW(...) do { if (log_level>=LL_WARNING) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogE(...) do { if (log_level>=LL_ERROR) fprintf(stderr, __VA_ARGS__); } while (0)
#define LogC(...) do { if (log_level>=LL_CRITIC) fprintf(stderr, __VA_ARGS__); } while (0)
extern LL_LOG log_level;
#endif


void setLogLevel(LL_LOG level);
LL_LOG getLogLevel();

#endif /* LOG_H_ */
