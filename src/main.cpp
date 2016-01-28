#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ostream>
#include <iostream>

#include "Constants.h"
#include "ConfigManager.h"
#include "WidgetManager.h"
#include "SyncManager.h"
#include "widgets/Widget.h"
#include "widgets/TimeWidget.h"

#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Ecore_Con.h>
#include <Edje.h>
#include <Elementary.h>

Evas        *evas;

using namespace std;
using namespace patch;
 
EAPI_MAIN int
elm_main(int argc, char **argv)
{
	Evas_Object *win;
	Evas_Object *bg;

	elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);

	win = elm_win_util_standard_add("La Boite", "La Boite");
	elm_win_autodel_set(win, EINA_TRUE);
	evas_object_resize(win, ScreenWidth, ScreenHeight);
	
	CM::I()->setWindow(win);
	evas =  evas_object_evas_get(win);
   	CM::I()->setCanvas(evas);

	evas_object_show(win);
	
	Widget *time_widget = new TimeWidget();
	
	WidgetManager manager(CM::ScreenW,CM::ScreenH);
	manager.addWidget(time_widget);
	
	SyncManager truc("9c865b88");
	truc.addListener(App::Time, time_widget);
	
	elm_run();
	return 0;
}
ELM_MAIN()
