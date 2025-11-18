#!/bin/bash

useradd -ms /bin/bash $USERNAME
echo "$USERNAME:$PASSWORD" | chpasswd
service ssh start
/bin/bash 
