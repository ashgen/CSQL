#!/usr/bin/perl

use strict;
use warnings;

my $file='log.txt';
my $outfile='prices.txt';
open(my $fh,$file) or die "Could not open file $file";
open(my $fo,'>',$outfile) or die "Could not open file $outfile";
print $fo "EsteeID,Date,OpenInterest,SettlementPrice,Open,High,Low,Close,Volume,TradedVal\n";
while(my $row=<$fh>){
	chomp $row;
	if ($row =~ /^\s*$/){
		next;
	}
	$row =~ s/^\[.*\]\s+(.*)$/\1/g;
	print $fo "$row\n";
}
close $fh; 
close $fo;
print "Done"
