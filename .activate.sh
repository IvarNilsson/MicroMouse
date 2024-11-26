ARDUINO_CLI_VERSION="$(arduino-cli version | awk -F ' ' '{print $3}')"
echo "arduino-cli version: $ARDUINO_CLI_VERSION"

# check for c++ libs
# sudo apt install libsfml-dev

#
# mlocate
#
# Check that mlocate is installed, as its required later.
# locate is used to allow for diffrences in install location
# between systems and are faster than find in the common case.
# NOTE: update db and check prune patterns if trouble shooting
if [ ! "$(command -v locate)" ]; then
    echo "\033[1;41mERROR: Please install 'plocate'\033[0m"
    return 0
fi

# 'venv' setup and activation
VENV_NAME=".venv"
# TODO: trigger on changes to requirements.txt to stay up to date.
# NOTE: to slow to always run
if [ ! -d "$VENV_NAME" ]; then
    echo -e "Python environment setup"
    python3 -m venv $VENV_NAME
    python3 -m ensurepip --default-pip
    $VENV_NAME/bin/python3 -m pip install setuptools wheel
    $VENV_NAME/bin/python3 -m pip install -r requirements.txt
fi
# TODO: Add explicit python min version and check
source $VENV_NAME/bin/activate
python3 --version

#
# Useful aliases
#
GIT_ROOT=$(git rev-parse --show-toplevel)
ETHERNET_ROOT=$GIT_ROOT/zcu216/ethernet_module
TESTS_ROOT=$ETHERNET_ROOT/tests

alias build="zsh $TESTS_ROOT/run.sh"
alias remove_vivado_files="sh $TESTS_ROOT/remove_vivado_files.sh"

echo -e '
Welcome to Ethernet Testin and Verification!
\033[4mCommands:\033[0m
\033[1m  build --help            \033[0m
\033[1m  remove_vivado_files --help     \033[0m
'

#
# Cleanup
#
unset GIT_ROOT ETHERNET_ROOT TESTS_ROOT
unset ARDUINO_CLI_VERSION
