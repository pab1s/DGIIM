#!/bin/bash

archivos=./fedora # Carpeta que contiene los archivos que necesitamos
if [ -f /tmp/kernel32-3.0.4 ];
then
	find /tmp/kernel32-3.0.4 &&
	find /tmp/Fedora14-x86-root_fs
else
	cp $archivos/*.gz /tmp &&
	gunzip -f /tmp/*.gz &&
	chmod +x /tmp/kernel32-3.0.4
fi

cd /tmp

./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m
