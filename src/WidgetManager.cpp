/*
 * WidgetManager.cpp
 *
 *  Created on: 21 Oct 2015
 *      Author: mickael
 */

#include "WidgetManager.h"

#include "Log.h"

using namespace std;

namespace patch {

WidgetManager::WidgetManager(int width, int height) :
	Widget((CM::EDJE_PATH+"home.edj").c_str(),"laboite.home",0,0,width,height, true)
{
}

WidgetManager::~WidgetManager() {

}

void WidgetManager::addWidget(Widget* widget) {
	_widgetList.push_back(widget);
	elm_layout_box_append(_obj, "laboite.box", widget->evas());
}

} /* namespace patch */
