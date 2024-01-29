#!/bin/bash

echo "[LOG]Im running!$$." >> /home/mm/Desktop/log # FOR LOGGING
pid=$(/home/mm/Desktop/crash.sh&)
wait $pid


