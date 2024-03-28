#!/bin/sh

VENV_DIR="django_env"
PYTHON_PATH="/usr/bin/python3"

echo "====================DO YOU KNOW E SAE KAI?======"
echo "=========IT'S WONDERFUL========================="

echo "===============I WILL SHOW YOU=================="
$PYTHON_PATH -m venv $VENV_DIR
source $VENV_DIR/bin/activate



python -m pip --version
echo "OH========YOUR PIP VERSION IS LOW=============OH"

pip install --upgrade pip
echo "=======AND INSTALL REQUIREMENT=================="

python -m pip install --force-reinstall -r requirement.txt