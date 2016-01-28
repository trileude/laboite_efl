/*
 * basictypes.h
 *
 *  Created on: 16 Oct 2015
 *      Author: mickael
 */

#ifndef SRC_BASICTYPES_H_
#define SRC_BASICTYPES_H_

#ifndef PACKAGE_DATA_DIR
#define PACKAGE_DATA_DIR "bin"
#endif

#include <stdint.h>
#include <string>

enum App{Time,Bike,Weather,Stop};

struct Pos{
	Pos(int px = 0, int py = 0) :
		x(px), y(py)
	{}
	int x;
	int y;
};

struct Color{
	Color(int r = 0, int g = 0, int b = 0, int a = 255) :
		red(r),green(g),blue(b),alpha(a)
	{}

	int red;
	int green;
	int blue;
	int alpha;
};



#endif /* SRC_BASICTYPES_H_ */
