/*
 * TimeWidget.h
 *
 *  Created on: 16 Oct 2015
 *      Author: mickael
 */

#ifndef SRC_WIDGET_TIME_H_
#define SRC_WIDGET_TIME_H_

#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>

#include "Widget.h"
#include "../basictypes.h"

namespace patch {

class TimeWidget : public Widget{
public:
	TimeWidget();
	virtual ~TimeWidget();
	virtual void refresh(const char* value);

protected:

};

}

#endif /* SRC_WIDGET_TIME_H_ */

