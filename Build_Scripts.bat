@echo OFF
Build\Windows\node\node.exe ./Build/Scripts/Bootstrap.js --task=build:genscripts %*
