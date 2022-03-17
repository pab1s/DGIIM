#!/bin/bash

find /home -atime 1 > modificados_`date +%Y-%d-%T`.txt
