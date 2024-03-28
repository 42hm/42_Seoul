#!/bin/sh
curl --silent $1 | grep "http\|https" | cut -d "\"" -f 2