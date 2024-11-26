ARDUINO_CLI_VERSION="$(arduino-cli version | awk -F ' ' '{print $3}')"
echo "arduino-cli version: $ARDUINO_CLI_VERSION"

# check for c++ libs
# libsfml-dev
libsfml_dev=$(apt list -qq libsfml-dev 2>/dev/null)
if [[ $libsfml_dev == *"[installed]" ]]; then
    libsfml_dev_version=$(echo "$libsfml_dev" | grep -oP '(?<=libsfml-dev/jammy,now )\d+\.\d+\.\d+')
    echo "libsfml-dev version $version"
else
    echo "libsfml-dev not installed. Use 'sudo apt install libsfml-dev' to install it."
fi

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
unset ARDUINO_CLI_VERSION libsfml_dev libsfml_dev_version
