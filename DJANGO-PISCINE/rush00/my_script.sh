#!/bin/sh

VENV_DIR="rush00_venv"
PYTHON_PATH="/usr/bin/python3"

pip3 install virtualenv
python3 -m venv $VENV_DIR
echo "################################################"
source $VENV_DIR/bin/activate
echo "################################################"

pip install --upgrade pip

python -m pip install --force-reinstall -r requirement.txt
