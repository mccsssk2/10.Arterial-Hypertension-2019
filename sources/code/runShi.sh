#!/bin/bash
#
# This script runs the Shi program, and renames the outputs to help post processing.
# whichPar goes from 1 to 7, the total number of parameters being considered.
# parFold goes till 200, to make maximum increase 100 fold.

for ((whichPar=1; whichPar<=7; whichPar++))
	do
	for (( parFold=1; parFold<=200; parFold++))
		do
			echo "./shi ${parFold} $whichPar" >> job_file
		done
	done

parallel -j 32 < job_file
