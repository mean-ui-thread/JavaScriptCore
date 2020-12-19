#!/bin/bash

pushd $(dirname "${BASH_SOURCE[0]}")

rm -rf webkitgtk-*

wget https://webkitgtk.org/releases/webkitgtk-unstable.tar.xz
tar xf webkitgtk-unstable.tar.xz

if [ -d Source ]; then 
	rm -rf Source
fi

WEBKIT_DIR=`find . -type d -name "webkitgtk-*"`

if [ -d ${WEBKIT_DIR} ]; then 
	cp -R ${WEBKIT_DIR}/* .
	pushd Source/ThirdParty
	git checkout gtest/CMakeLists.txt
	popd
fi

popd
