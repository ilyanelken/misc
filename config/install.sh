#!/bin/bash

set -e

HOME_DIR=`dirname $0`
NERD_TREE_REPO="https://github.com/scrooloose/nerdtree.git"

echo -n "Installing configurations ... "

######################
# General config files
######################
for file in vimrc bashrc gitconfig
do
	cp -f $HOME_DIR/.$file ~/
done

source ~/.bashrc

###################
# GIT configuration
###################
if [ ! -d ~/bin ]; then
	mkdir ~/bin
fi

cp -f $HOME_DIR/git_files/* ~/bin

###################
# VIM configuration
###################
cd ~/.vim/bundle/
if [ ! -d "nerdtree" ]; then
	git clone $NERD_TREE_REPO > /dev/null
fi

echo "succeeded"
