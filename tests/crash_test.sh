#!/bin/bash
counter=1

while [ $counter -le 50 ]
do
	../mlx ../maps/mars.fdf &
	../mlx ../maps/mars.fdf &
	sleep 2
	killall "mlx"
	((counter++))
done

echo All done
