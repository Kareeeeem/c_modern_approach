#!/bin/bash

# Start working on a chapter in a tmux pane
# Create the folder if it doesn't exist yet.

if [ -z "$1" ]
then
    echo "Please specify a chapter to work on."
    exit 1
else
    CHAPTER="ch$1"
fi

if [ ! -d "$CHAPTER" ];
then
    mkdir $CHAPTER
    cp ./ch2/Makefile $CHAPTER
fi

# Start a new session in the chapter folder
tmux new-session -d -c $CHAPTER -s MC-$CHAPTER

tmux rename-window 'vim'

# Start up vim and mark the pane to return to it later.
tmux send-keys "vim" ENTER C-a C-m

# Split the window vertically, give it 20% of the window height.
# Start it in the same directory.
tmux split-window -v -p 20 -c "#{pane_current_path}"

# Add the bin folder to the path.
tmux send-keys "PATH=./bin:$PATH" ENTER C-a C-l

# Return to the marked pane.
tmux select-pane

tmux a -d
