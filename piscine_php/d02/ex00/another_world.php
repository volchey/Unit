#!/usr/bin/php
<?php

$res = preg_replace("/\t/", " ", $argv[1]);
$res = preg_replace("/[ ]+/", " ", $res);
$res = trim($res);
echo "$res\n";

?>