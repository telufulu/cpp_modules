#!/bin/sh

SCRIPT_DIR=$1
INSTALL_DIR="$(cd "$(dirname "$0")" && pwd)"

# Default path /usr/local/scripts.
if [ -z "$SCRIPT_DIR" ]; then
    SCRIPT_DIR=/usr/local/scripts
fi

# Creates the directory if it doesn't exists (sudo is required)
if [ ! -d "${SCRIPT_DIR}" ]; then
    sudo mkdir -p "${SCRIPT_DIR}"
fi

sudo cp "${INSTALL_DIR}/newcpp"  "${SCRIPT_DIR}/"
sudo cp "${INSTALL_DIR}/mkclass" "${SCRIPT_DIR}/"
sudo chmod +x "${SCRIPT_DIR}/newcpp" "${SCRIPT_DIR}/mkclass"

cat << EOF
✔️ Instalation complete

Scripts were installed at:
${SCRIPT_DIR}/

Try to execute:

newcpp <projectName>
mkclass <className>

EOF
