/*
 * SyncManager.h
 *
 *  Created on: 27 Jan 2016
 *      Author: Emmanuel
 */

#ifndef SRC_SYNCMANAGER_H_
#define SRC_SYNCMANAGER_H_

#include "ConfigManager.h"
#include "basictypes.h"
#include "widgets/Widget.h"

#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>
#include <Elementary.h>

namespace patch {

class SyncManager{
public:
	SyncManager(std::string api_key);
	virtual ~SyncManager();
	void parseJson(std::string json);
	void addListener(App type, Widget* widget);

protected:
	static Eina_Bool url_data_cb(void *data EINA_UNUSED, int type EINA_UNUSED, void *event_info);
	void refreshListener(std::vector<Widget*> *listeners, const char* value);
	
	std::string _apiKey;
	Ecore_Con_Url *_clientHttp;
	std::vector<Widget*> _timeListener;
	std::vector<Widget*> _bikeListener;
	std::vector<Widget*> _stopListener;
	std::vector<Widget*> _weatherListener;
};

} /* namespace patch */

#endif /* SRC_SYNCMANAGER_H_ */

