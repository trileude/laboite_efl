/*
 * SyncManager.cpp
 *
 *  Created on: 21 Oct 2015
 *      Author: mickael
 */

#include "SyncManager.h"
#include "rapidjson/document.h"

#include "Log.h"

using namespace std;

namespace patch {

SyncManager::SyncManager(std::string api_key) :
	_apiKey(api_key)
{
	ecore_con_init();
	ecore_con_url_init();
	string uri = "http://api.laboite.cc/"+ api_key +".json";
	_clientHttp = ecore_con_url_custom_new(uri.c_str(), "GET");
	ecore_event_handler_add(ECORE_CON_EVENT_URL_DATA, &SyncManager::url_data_cb, this);
	Eina_Bool r = ecore_con_url_get(_clientHttp);
	if(!r) {
		LogE("Failed to fetch uri\n");
	}
}

SyncManager::~SyncManager() {
	ecore_con_url_free(_clientHttp);
	ecore_con_url_shutdown();
	ecore_con_shutdown();
}

void SyncManager::parseJson(std::string json) {
	LogD("Result = %s\n", json.c_str());
	rapidjson::Document d;
	d.Parse<0>(json.c_str());
	LogD("Time : %s\n", d["time"].GetString());
	refreshListener(&_timeListener, d["time"].GetString());
}

void SyncManager::refreshListener(std::vector<Widget*> *listeners, const char* value) {
	for(Widget *widget : *listeners){
		widget->refresh(value);
	}
}

void SyncManager::addListener(App type, Widget* widget) {
	switch(type) {
		case App::Time:
		{
			_timeListener.push_back(widget);
			break;
		}
		case App::Bike:
		{
			_bikeListener.push_back(widget);
			break;
		}
		case App::Weather:
		{
			_weatherListener.push_back(widget);
			break;
		}
		case App::Stop:
		{
			_stopListener.push_back(widget);
			break;
		}
		default:
		break;
	}
}

Eina_Bool SyncManager::url_data_cb(void *data, int type EINA_UNUSED, void *event_info) {
	SyncManager *manager = reinterpret_cast<SyncManager*>(data);
	Ecore_Con_Event_Url_Data *url_data = (Ecore_Con_Event_Url_Data*)event_info;
	
	string json((const char*)url_data->data, url_data->size);
	
	manager->parseJson(json);
	
	return EINA_TRUE;
}


} /* namespace patch */
