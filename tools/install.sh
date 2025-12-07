#!/bin/bash

SCRIPT_DIR=$1

if [ -z "$SCRIPT_DIR"]; then
	$SCRIPT_DIR = ~/.scripts
fi

if [ ! -d ${SCRIPT_DIR} ]; then
	mkdir ${SCRIPT_DIR}
fi

cp mkclass ${SCRIPT_DIR}
cp newcpp ${SCRIPT_DIR}
