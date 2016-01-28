/*
 * ConfigManager.h
 *
 *  Created on: 22 Oct 2015
 *      Author: mickael
 */

#ifndef SRC_CONFIGMANAGER_H_
#define SRC_CONFIGMANAGER_H_

#include "basictypes.h"

#include <vector>
#include <string>

#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>

namespace patch {

class Widget;

class ConfigManager {
public:

	virtual ~ConfigManager();

	static ConfigManager *I();

	Evas* canvas() const;
	void setCanvas(Evas* canvas);
	Evas_Object* window() const;
	void setWindow(Evas_Object* windows);

	static const int ScreenW;
	static const int ScreenH;
	static const int WidgetW;
	static const int WidgetH;
	static const int MarginX;
	static const int MarginY;

	static const std::string RESOURCE_PREFIX_PATH;
	static const std::string EDJE_PATH;
protected:

	ConfigManager();

	static ConfigManager *_instance;

	Evas *_canvas;
	Evas_Object *_window;

};

typedef ConfigManager CM;

} /* namespace patch */

#endif /* SRC_CONFIGMANAGER_H_ */
