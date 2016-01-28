/*
 * ConfigManager.cpp
 *
 *  Created on: 22 Oct 2015
 *      Author: mickael
 */

#include "ConfigManager.h"

#include "Constants.h"

using namespace std;

namespace patch {

ConfigManager *ConfigManager::_instance = 0;

const int ConfigManager::ScreenW = ScreenWidth;
const int ConfigManager::ScreenH = ScreenHeight;

const int ConfigManager::WidgetW = WidgetWidth;
const int ConfigManager::WidgetH = WidgetHeight;

const int ConfigManager::MarginX = 0;
const int ConfigManager::MarginY = 0;

#ifdef RESOURCE_PREFIX
	const string ConfigManager::RESOURCE_PREFIX_PATH = RESOURCE_PREFIX;
	const string ConfigManager::EDJE_PATH = RESOURCE_PREFIX_PATH+"/edj-factory/";
#else
	const string ConfigManager::RESOURCE_PREFIX_PATH = "./";
	const string ConfigManager::EDJE_PATH = RESOURCE_PREFIX_PATH+"/bin/";
#endif

Evas_Object* ConfigManager::window() const {
	return _window;
}

void ConfigManager::setWindow(Evas_Object* windows) {
	_window = windows;
}

ConfigManager::ConfigManager() :
	_canvas(NULL),
	_window(NULL)
{
}

ConfigManager::~ConfigManager() {
}

ConfigManager *ConfigManager::I(){
	if(_instance == 0){
		_instance = new ConfigManager();
	}
	return _instance;
}

Evas* ConfigManager::canvas() const {
	return _canvas;
}

void ConfigManager::setCanvas(Evas* canvas) {
	_canvas = canvas;
}

} /* namespace patch */

