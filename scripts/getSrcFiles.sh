#!/bin/bash

# constants:
SENDTONULL="/dev/null"
CHECKFILETYPE=\.cpp

# recursively go through all directories and collect all .cpp files; methods to do so
REQEXTENSION=".cpp"
ISDIRTEXT="is a directory"

## adds backslash after the name of a file/dir so that whether they are dir can be tested
addBackSlash(){
    # argument for where the directory to be searched
    TOSEARCHDIR="$1"
    ## if input does not have '/' at the end then add it
    lastCharIndex=${#TOSEARCHDIR}
    lastChar=$(echo ${TOSEARCHDIR} | cut -c ${lastCharIndex})
    if [ $lastChar  != / ]
    then
        TOSEARCHDIR=$TOSEARCHDIR/
    fi
    
    echo $TOSEARCHDIR
}

## determine whether a given name is a directory or not:
isDir(){
    # add a / at the end of the str
    # calling name with / at end will return either is or is not dir
    targetName="$1"
    if [ $(echo $1 | cut -c ${#targetName}) != / ]
    then
        targetName=$targetName/
    fi

    # check whether directory or not
    isDirStr="$(dir -d $targetName 2> ${SENDTONULL})"
    if [[ $isDirStr == "" ]]
    then
        echo NO
    else
        echo YES
    fi
}

## recursive search through directory
getDirContents () {
    returnContents=""
    pathPrefix="$1"
    contents=$(ls $pathPrefix)
    read -ra contents -d ' ' <<<"$contents"
    for i in "${contents[@]}"
    do
        # determine whether name is a directory or not
        backslashAddedName="$(addBackSlash ${i})"
        isNameADir="$(isDir "${pathPrefix}${backslashAddedName}")"

        # if the name is a directory then follow it and get the .cpp files within it
        if [[ $isNameADir == YES ]]
        then
            nestedContents=$(getDirContents "${pathPrefix}${backslashAddedName}")
            returnContents="${returnContents} ${nestedContents}"
        fi

        # if the name has .cpp in it then collect it into a list and echo it
        if [[ $i =~ .*$CHECKFILETYPE ]]
        then
            # add the name without backslash to the list
            returnContents="${returnContents} ${pathPrefix}${i}"
        fi

    done

    echo $returnContents
}


# Driver code:

## add backslash to original input if it is not there already
inputDir=$(addBackSlash ${1})

## generate .cpp file list
getDirContents $inputDir