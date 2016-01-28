/*
 * WidgetManager.h
 *
 *  Created on: 27 Jan 2016
 *      Author: Emmanuel
 */

#ifndef SRC_WIDGETMANAGER_H_
#define SRC_WIDGETMANAGER_H_

#include "widgets/Widget.h"
#include "ConfigManager.h"

#include <vector>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>
#include <Elementary.h>

namespace patch {

class WidgetManager : public Widget{
public:
	WidgetManager(int width, int height);
	virtual ~WidgetManager();

	void addWidget(Widget *widget);

protected:
	std::vector<Widget*> _widgetList;
	Evas_Object *_box;
};

} /* namespace patch */

#endif /* SRC_WIDGETMANAGER_H_ */
