/*
 * widget.c
 *
 *  Created on: 16 Oct 2015
 *      Author: mickael
 */

#include "TimeWidget.h"
#include "../ConfigManager.h"

#include "../Log.h"

#include <Edje.h>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Elementary.h>

namespace patch {

TimeWidget::TimeWidget() :
	Widget((CM::EDJE_PATH+"time.edj").c_str(),"laboite.time",CM::MarginX,CM::MarginY,CM::WidgetW,CM::WidgetH, true)
{
	
}

TimeWidget::~TimeWidget(){

}

void TimeWidget::refresh(const char* value) {
	elm_object_part_text_set(_obj, "time", value);
}

}

