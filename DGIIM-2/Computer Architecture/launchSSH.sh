#!/bin/bash
#Nombre:       launchSSH.sh
#Autor:	       Daniel Pérez Ruiz
#Version:      1.0
#Descripción:  Lanza el secure shell (SSH) del ATCGRID
#Uso:	       ./launchSSH.sh

echo -e "PASSWORD: password"
echo -e "PS1=\"[NombreApellido1Apellido2 \u@\h:\w] \D{%F %A}\n$\""

#NOTA: MODIFICAR LA ORDEN PARA PONER TU USUARIO DEL ATCGRID
ssh -X user

