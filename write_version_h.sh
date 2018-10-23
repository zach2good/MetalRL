#!/usr/bin/env bash

TARGET_FILE="$1"
TARGET_DIR=`dirname ${TARGET_FILE}`

GIT_BRANCH=`git rev-parse --abbrev-ref HEAD`
GIT_COMMIT_HASH=`git log -1 --format=%h`
GIT_DATE=`git log -1 --format=%ad --date=local`
GIT_COMMIT_SUBJECT=`git log -1 --format=%s`
BUILD_DATE=`date`

echo "======= BUILD INFORMATION ======"
echo Target File: ${TARGET_FILE}
echo GIT_BRANCH: ${GIT_BRANCH}
echo GIT_COMMIT_HASH: ${GIT_COMMIT_HASH}
echo GIT_DATE: ${GIT_DATE}
echo GIT_COMMIT_SUBJECT: ${GIT_COMMIT_SUBJECT}
echo BUILD_DATE: ${BUILD_DATE}

touch ${TARGET_FILE}

echo "#pragma once" > ${TARGET_FILE}
echo "#define GIT_BRANCH \"${GIT_BRANCH}\"" >> ${TARGET_FILE}
echo "#define GIT_COMMIT_HASH \"${GIT_COMMIT_HASH}\"" >> ${TARGET_FILE}
echo "#define GIT_DATE \"${GIT_DATE}\"" >> ${TARGET_FILE}
echo "#define GIT_COMMIT_SUBJECT \"${GIT_COMMIT_SUBJECT}\"" >> ${TARGET_FILE}
echo "#define BUILD_DATE \"${BUILD_DATE}\"" >> ${TARGET_FILE}




