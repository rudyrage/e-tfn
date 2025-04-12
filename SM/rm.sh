#!/bin/bash

# Start a new tmux session in detached mode
tmux new-session -d -s mysession

# Loop to create 10 panes and run the commands
for n in {1..10}
do
    # Split the window into horizontal panes (2 panes first)
    if [ $n -gt 1 ]; then
        tmux split-window -h
    fi

    # Run the command in the current pane
    tmux send-keys "gcc ${n}.c -o /tmp/a.out && /tmp/a.out && ssc ${n}.png" C-m
done

# Attach to the tmux session
tmux attach -t mysession
