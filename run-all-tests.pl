#!/usr/bin/perl
#
use strict;

my $dir = 'all-gcf';

mkdir $dir;

for (my $sector = 12; $sector <= 16; $sector++) {
    for (my $block = 0; $block <= 2; $block++) {
        for (my $page = 8; $page <= 10; $page++) {
                for (my $magic = 0; $magic <= 1; $magic++) {
                    system("make clean test FLAGS=\"-DBLOCK_SECTOR_BITS=$block -DSECTOR_BITS=$sector -DPAGE_BITS=$page -DSPIFFS_USE_MAGIC=$magic\" > $dir/s=$sector,block=$block,page=$page,magic=$magic");
                }

        }
    }
}
