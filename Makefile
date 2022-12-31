

function_enums.c:

functions.c:

function_names.c:

functions_PROGMEM.c:

function_doc.c:

ulisp.tmpl:

build: build.py function_enums.c functions.c function_names.c functions_PROGMEM.c function_doc.c ulisp.tmpl
	python build.py

compile: build
	arduino-cli compile --fqbn esp32:esp32:esp32 ulisp

upload: build
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 ulisp



