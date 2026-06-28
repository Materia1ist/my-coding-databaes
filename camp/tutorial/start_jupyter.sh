
#!/bin/bash

# Set custom notebook directory
NOTEBOOK_DIR="$HOME/Desktop/tutorial"
PORT=8888

# Create directory if it doesn't exist
mkdir -p "$NOTEBOOK_DIR"

# Check Jupyter installation
if ! command -v jupyter &> /dev/null; then
    echo "Error: Jupyter not found. Install with: pip install jupyterlab"
    exit 1
fi

# Launch with custom settings
jupyter notebook \
    --port="$PORT" \
    --no-browser \
    --notebook-dir="$NOTEBOOK_DIR" \
    --NotebookApp.token=''

