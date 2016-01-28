/*
 * widget.h
 *
 *  Created on: 16 Oct 2015
 *      Author: mickael
 */

#ifndef SRC_WIDGET_H_
#define SRC_WIDGET_H_

#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>

#include "../basictypes.h"

namespace patch {

class Widget{
public:
	Widget(Evas_Object *obj);
	Widget(const char *filename,const char *groupe,
			int x, int y, int width, int heigh, bool isElmentary = false);
	virtual ~Widget();

	void move(int x, int y);

	void moveByDeltat(int xDelta, int yDelta);

	Pos pos();

	Evas_Object *evas() const{return _obj;}

	void setAlpha(int alpha);
	int alpha() const;
	
	virtual void refresh(const char* value);

	virtual void show();
	virtual void hide();

	virtual void onClick(){};

	static void init_widget_elm_edje_file(Widget *widget,const char *filename,const char *groupe,
			int x, int y, int width, int heigh);

	static void init_widget_edje_file(Widget *widget, const char *filename,const char *groupe,
			int x, int y, int width, int heigh);

protected:
	Evas_Object *_obj;
	Evas_Object *_conform;

	Color _initColor;

};

}

#endif /* SRC_WIDGET_H_ */

