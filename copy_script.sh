#!/bin/bash

# Function to copy a file using system calls
copy_file() {
  local src_file="Ram.txt"
  local dest_file="Tripathi.txt"

  # Check if the source file exists
  if [[ ! -f "$src_file" ]]; then
    echo "Source file does not exist: $src_file"
    exit 1
  fi

  # Open the source and destination files using file descriptors
  exec 3< "$src_file"  # Open source file for reading
  exec 4> "$dest_file" # Open destination file for writing

  # Read the content of the source file into a buffer and write it to the destination
  local buffer
  read -r -d '' buffer <&3  # Read the entire file into 'buffer'
  echo -n "$buffer" >&4     # Write 'buffer' to the destination file

  # Close the file descriptors
  exec 3<&-
  exec 4>&-

  echo "File copied successfully from $src_file to $dest_file"
}

# Call the copy_file function
copy_file
