#!/bin/sh

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/home/ddeboni/src/prototype:/home/ddeboni/src/prototype/plugins"
export POWERAPI_CONFIG="/home/ddeboni/src/prototype/examples/teller.xml"
export POWERAPI_ROOT="plat.cab0.board0.node0"

./example