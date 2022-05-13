#!/bin/bash

# constants:
SENDTONULL="/dev/null"
CHECKFILETYPE=\.cpp

# adds backslash after the name of a file/dir so that whether they are dir can be tested
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

# recursively go through all directories and collect all .cpp files
REQEXTENSION=".cpp"
ISDIRTEXT="is a directory"

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


dirCppFiles (){
    echo "${getDirContents $1}"
}

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
            returnContents="${returnContents} ${pathPrefix}${backslashAddedName}"
        fi

    done

    echo $returnContents
}

getDirContents $1