#!/usr/bin/php
<?php

$d_week = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");
$e_month = array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");
$f_month = array("/janvier/i", "/février/i", "/mars/i", "/avril/i", "/mai/i", "/juin/i", "/juillet/i", "/août/i", "/septembre/i", "/octobre/i", "/novembre/i", "/décembre/i");
$f_month_upp = array("Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre");
// $arr = preg_split("/ /", $argv[1]);
$i = preg_replace($f_month, $e_month, $argv[1]);
// if ($i = preg_match($arr[1], $f_month))
// strtolower($argv[1][0]);
print_r($i);
// print_r($f_month);
// echo strtotime();

?>