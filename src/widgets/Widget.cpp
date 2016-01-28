/*
 * widget.c
 *
 *  Created on: 16 Oct 2015
 *      Author: mickael
 */

#include "Widget.h"

#include "../ConfigManager.h"
#include "../Log.h"

#include <Edje.h>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Elementary.h>

namespace patch {

Widget::Widget(Evas_Object *obj) :
	_obj(obj),
	_initColor(),
	_conform(NULL)
{
	evas_object_color_get(_obj,
			&_initColor.red,
			&_initColor.green,
			&_initColor.blue,
			&_initColor.alpha);
}

Widget::Widget(const char *filename,const char *groupe,
		int x, int y, int width, int heigh, bool isElementary) :
	_obj(NULL),
	_initColor(),
	_conform(NULL)
{
	if(isElementary){
		init_widget_elm_edje_file(this,filename,groupe,x,y,width,heigh);
	}
	else{
		init_widget_edje_file(this,filename,groupe,x,y,width,heigh);
	}

	evas_object_color_get(_obj,
			&_initColor.red,
			&_initColor.green,
			&_initColor.blue,
			&_initColor.alpha);
}

Widget::~Widget(){
	hide();

	if(_conform != NULL){
		elm_object_content_unset(_conform);
	}
	evas_object_del(_obj);
}

Pos Widget::pos(){
	int w,h;
	Pos pos;
	evas_object_geometry_get(_obj,&pos.x,&pos.y,&w,&h);
	return pos;
}

void Widget::moveByDeltat(int xDeltat,int yDeltat){
	evas_object_move(_obj, pos().x + xDeltat , pos().y + yDeltat);
}

void Widget::move(int x,int y){
	if(_obj == NULL){
		LogE("Widget::move\n");
	}
	evas_object_move(_obj, x, y);
}

void Widget::show(){
	evas_object_show(_obj);
}

void Widget::hide(){
	evas_object_hide(_obj);
}

void Widget::setAlpha(int alpha) {
	float value = (float)alpha / 255;
	_initColor.alpha = alpha;
	evas_object_color_set(
			_obj,
			_initColor.red * value,
			_initColor.green * value,
			_initColor.blue * value,
			_initColor.alpha
	);
}

int Widget::alpha() const{
	return _initColor.alpha;
}

void Widget::refresh(const char* value) {
	//need to be implemented in sub-classes
}

void Widget::init_widget_elm_edje_file(Widget *widget, const char *filename,const char *groupe,
		int x, int y, int width, int heigh){

    // Conformant
	widget->_conform = elm_conformant_add(CM::I()->window());
    evas_object_size_hint_weight_set(widget->_conform, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
    elm_win_resize_object_add(CM::I()->window(), widget->_conform);

    evas_object_show(widget->_conform);

    widget->_obj = elm_layout_add(widget->_conform);
    elm_layout_file_set(widget->_obj,  filename, groupe);
    evas_object_move(widget->_obj,x,y);
    evas_object_resize(widget->_obj, width,heigh);
    evas_object_show(widget->_obj);
}

void Widget::init_widget_edje_file(Widget *widget,const char *filename,const char *groupe, int x, int y, int width, int heigh){
	Evas_Object *edje_obj;
	edje_obj = edje_object_add(CM::I()->canvas());
	edje_object_file_set(edje_obj, filename, groupe);
	evas_object_move(edje_obj, x, y);
	evas_object_resize(edje_obj, width, heigh);
	evas_object_show(edje_obj);

	widget->_obj=edje_obj;
}

}

