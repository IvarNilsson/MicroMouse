ARDUINO_CLI_VERSION="$(arduino-cli version | awk -F ' ' '{print $3}')"
echo "arduino-cli version: $ARDUINO_CLI_VERSION"

# check for c++ libs
# sudo apt install libsfml-dev


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
