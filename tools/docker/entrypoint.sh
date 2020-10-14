#!/bin/bash

if [ ! -d "${HOME}/.mkf/" ]; then
    mkdir -p ${HOME}/.bigbang/
fi

if [ ! -f "${HOME}/.mkf/mkf.conf" ]; then
    cp /bigbang.conf ${HOME}/.mkf/mkf.conf
fi

exec "$@"
