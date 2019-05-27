#!/bin/sh

## This job must be executed on VM2 machines
## See ./README.md

## Nightly launched

echo "Job 5"
casejob=5
# change default  compilator  
change_compilator=/etc/jenkins/change_compilator-`uname -s`-`uname -r`-$casejob.sh
echo try to source file  "$change_compilator"
test -f "$change_compilator" && echo  source file "$change_compilator" 
test -f "$change_compilator" && cat  "$change_compilator"
test -f "$change_compilator" && source "$change_compilator"


# configuration & build
autoreconf -i \
  && ./configure  --enable-download --without-mpi --enable-debug --prefix=/builds/workspace/freefem \
  && ./3rdparty/getall -a \
  && chmod +x ./etc/jenkins/blob/build.sh && sh ./etc/jenkins/blob/build.sh

if [ $? -eq 0 ]
then
  echo "Build process complete"
else
  echo "Build process failed"
  exit 1
fi

# check
chmod +x ./etc/jenkins/blob/check.sh && sh ./etc/jenkins/blob/check.sh

if [ $? -eq 0 ]
then
  echo "Check process complete"
else
  echo "Check process failed"
fi

# install
chmod +x ./etc/jenkins/blob/install.sh && sh ./etc/jenkins/blob/install.sh

if [ $? -eq 0 ]
then
  echo "Install process complete"
else
  echo "Install process failed"
fi
