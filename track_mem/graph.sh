#!/bin/sh

# trap ctrl-c and call ctrl_c()
trap ctrl_c INT

LOG=$(mktemp)
SCRIPT=$(mktemp)
IMAGE=image.jpg

echo "Output to LOG=$LOG and SCRIPT=$SCRIPT and IMAGE=$IMAGE"

cat >$SCRIPT <<EOL
set term png small size 800,600
set output "$IMAGE"

set ylabel "RSS"
set y2label "%CPU"

set ytics nomirror
set y2tics nomirror in

set yrange [0:*]
set y2range [0:*]

plot "$LOG" using 3 with lines axes x1y1 title "RSS", \
	 "$LOG" using 2 with lines axes x1y2 title "%CPU"
EOL

function write_image() {
	gnuplot $SCRIPT
	open $IMAGE
	exit 0;
}

function ctrl_c() {
	kill -9 $APP_PID
	write_image
}

exec $1 & export APP_PID=$!

while ps -p $APP_PID > /dev/null; do
	ps -p $APP_PID -o pid=,%cpu=,rss= | tee -a $LOG
	sleep $2
done

write_image
