#!/bin/sh

GREEN="\033[1;32m"
RESET="\033[0m"

SCRIPT_DIR=$1
INSTALL_DIR="$(cd "$(dirname "$0")" && pwd)"

if [[ "$SHELL" == *"zsh" ]]; then
    RC_FILE="$HOME/.zshrc"
elif [[ "$SHELL" == *"bash" ]]; then
    RC_FILE="$HOME/.bashrc"
else
    echo "Shell no soportada"
    exit 1
fi

if [ -z "$SCRIPT_DIR" ]; then
	SCRIPT_DIR=~/.scripts
fi
if [ ! -d ${SCRIPT_DIR} ]; then
	mkdir ${SCRIPT_DIR}
fi

cp ${INSTALL_DIR}/newcpp ${SCRIPT_DIR}
cp ${INSTALL_DIR}/mkclass ${SCRIPT_DIR}

echo "" >> ${RC_FILE}
echo "#SCRIPTS ALIAS" >> ${RC_FILE}
echo "alias newcpp=\"sh ${SCRIPT_DIR}/newcpp\"" >> ${RC_FILE}
echo "alias mkclass=\"sh ${SCRIPT_DIR}/mkclass\"" >> ${RC_FILE}

cat << EOF
✔️ Instalation complete

Scripts were installed at:
  ${HOME}/.scripts/

Try to execute:

  newcpp <projectName>
  mkclass <className>
EOF

source ${RC_FILE}
