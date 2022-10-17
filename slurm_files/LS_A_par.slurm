#!/bin/bash
#SBATCH --partition fat
#SBATCH -D /home/bignardi/coercive_waves/
#SBATCH -c 1
#SBATCH --mem 200G
#SBATCH -t 12:00:00
#SBATCH --mail-user=paolo.bignardi01@universitadipavia.it
#SBATCH --mail-type=all  

module load matlab
matlab -r -nodisplay -nosplash
