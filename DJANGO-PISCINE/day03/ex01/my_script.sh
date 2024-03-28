#!/bin/sh


PATH_URL="https://github.com/jaraco/path.git"
PATH_FILE="my_program.py"
LOG_FILE="pip_path.log"
LIB_DIR="local_lib"
PYTHON_PATH="/usr/bin/python3"

echo "============I WANT TO SLEEP NOW============"
echo "============zz============================="
echo "==============zz==========================="
echo "================zz========================="
echo "==================zz======================="
rm -rf $LIB_DIR
$PYTHON_PATH -m venv $LIB_DIR
source $LIB_DIR/bin/activate

python -m pip --version
echo "OH=======your pip version is so low======OH"
pip install --upgrade pip
echo "=====appreciate to me======================"
echo "========install pppppaaaaaattttthhhhh======"


python -m pip install --log $LOG_FILE --force-reinstall git+$PATH_URL
echo "=========i installed the latest version===="

python $PATH_FILE