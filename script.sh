echo "List of plots with respective input values :"
echo "(Check the folder to find all output files and respective plots)"
ki=('1' '4')
km=('1.0' '1.5')
kn=('0.5' '1.0')
kf=('0.1' '0.3')
ps=('0.01' '0.0001')
cnt=0
for i1 in "${ki[@]}"
do
	for i2 in "${km[@]}"
	do
		for i3 in "${kn[@]}"
		do
			for i4 in "${kf[@]}"
			do
				for i5 in "${ps[@]}"
				do
					cnt=$((cnt+1))
					echo "Plot No - $cnt: ki = $i1, km = $i2, kn = $i3, kf = $i4, ps = $i5"
					./cw $i1 $i2 $i3 $i4 $i5 1000 output$cnt.txt
					python3 plot.py output$cnt.txt fig$cnt.png "ki = $i1, km = $i2, kn = $i3, kf = $i4, ps = $i5"
				done
			done
		done
	done 
done
