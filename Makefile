DEBUG = -DVERBOSE

CC = gcc
CXX = g++
PKG_CONFIG = pkg-config
ARCH = ${shell uname -m}

LIBRARIES = fontconfig freetype2 x11 xi cairo eina evas ecore ecore-evas ecore-con ecore-x edje elementary
CFLAGS := ${shell ${PKG_CONFIG} --cflags ${LIBRARIES}} -O3 $(DEBUG) $(RESOURCE_PATH)
CPPFLAGS = $(CFLAGS) -std=c++11
LDFLAGS := ${shell ${PKG_CONFIG} --libs ${LIBRARIES}}
INCLUDES =
EDJE_CC = edje_cc
PREF_CC = elm_prefs_cc
EDJE_FLAGS = -id image
LIBS =

OBJ_DIR=obj
SRC_DIR=src
BIN_DIR=bin
EDC_DIR=edc

WIDGET_DIR = widgets

SRC:= $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/ConfigManager.cpp \
	$(SRC_DIR)/WidgetManager.cpp \
	$(SRC_DIR)/SyncManager.cpp \
	$(SRC_DIR)/Log.cpp \
	$(SRC_DIR)/$(WIDGET_DIR)/Widget.cpp \
	$(SRC_DIR)/$(WIDGET_DIR)/TimeWidget.cpp

OBJ_TMP := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(ARCH)/%.o)
OBJ := $(OBJ_TMP:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(ARCH)/%.o)
 
print-%  : ; @echo $* = $($*)

SRC_EDC:= $(EDC_DIR)/home.edc \
	$(EDC_DIR)/time.edc
	
SRC_EDJ:= $(SRC_EDC:$(EDC_DIR)/%.edc=$(BIN_DIR)/%.edj)

TARGET = $(BIN_DIR)/$(ARCH)/la-boite

all: $(TARGET) $(SRC_EDJ)

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)
	
$(OBJ_DIR)/$(ARCH)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -o $@ -c $< $(CPPFLAGS) $(INCLUDES)

$(BIN_DIR)/%.edj: $(EDC_DIR)/%.edc
	@mkdir -p $(@D)
	$(EDJE_CC) $(EDJE_FLAGS) $< $@

clean:
	rm -rf $(OBJ_DIR)/$(ARCH)/*

clean-edj:
	rm -rf $(BIN_DIR)/*.edj

mrproper: clean clean-edj
	rm -f $(BIN_DIR)/$(ARCH)/*

distclean: mrproper
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean clean-edj mrproper distclean
