#!/bin/bash

# main manuscript figure 1.
cd Figure1A
mogrify -trim *.png
cd ..
cd Figure1B_SupplementaryEcho
mogrify -trim *.png
cd ..
cd Figure1C
mogrify -trim *.png
cd ..
# join the panel B panels.
cd Figure1B_SupplementaryEcho
convert +append figure1B_justAscendingAorta.png Figure1B_barChart_Aortic_measurements.png Figure1B.png
mogrify -trim Figure1B.png
cd ..
#
cd Figure1C
convert +append Figure1Ci_weight.png Figure1Cii_hr.png Figure1C.png
cd ..
#
# do your figure 1.
convert -append -resize 1600x2000 Figure1A/Figure1A_averagedBP.png Figure1B_SupplementaryEcho/Figure1B.png Figure1C/Figure1C.png Figure1_ClinicalData.png
# convert -append Figure1A/Figure1A_averagedBP.png Figure1B_SupplementaryEcho/Figure1B.png Figure1C/Figure1C.png Figure1_ClinicalData.png
#
# Supplementary figure.
#
cd Figure1B_SupplementaryEcho
convert +append FigS1_A_outflowTract_PanelA.png FigS1_B_valsalva_PanelB.png row1.png
convert +append FigS1_C_vasalva_PanelC.png FigS1_D_tubularAscending_PanelD.png row2.png
convert -append row1.png row2.png FigureS2.png
cd ..

