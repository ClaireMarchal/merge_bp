# fastq_length_filter


**************************************************************
Created by Claire Marchal at Universite Paris Diderot (FRANCE)
**************************************************************

The aim of this tool is to merge two genomic coordinates files to obtain shared
localizations at the base pair level. Files must be formated as following,
with tab used as a separator:

chromosome_name	 start	stop	peak_name

Nomenclature for chromosome must be identical for both coordinates files.
Files must be sorted by chromosome and positions.

# Installation

*** download the folder merge_bp:

git clone https://github.com/ClaireMarchal/merge_bp.git

*** go into the folder:

cd merge_bp

*** compile program:

make


# How to use

merge_bp [path to the first positions file] [path to the second positions file] [path to the newly created output file]


