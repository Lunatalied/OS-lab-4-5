#!/usr/bin/env bash
echo "export LD_LIBRARY_PATH"
DIR=$(cd "$(dirname "$0")"; pwd)
echo $DIR
 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DIR
