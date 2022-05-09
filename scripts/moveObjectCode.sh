#!/bin/bash

# get the directory from which to move the object files
FROMDIR=$1

# directory to which object files will be moved:
TODIR=$2

# get list of all object files (extension: .o)
filesInDir=$("ls")

# for now print the files
echo $filesInDir
