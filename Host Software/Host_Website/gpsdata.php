<?php 

require 'config.php';

function ConvDecimalMinutestoDecimalDdegrees_lat($lat) 
{
  $latDegrees=substr($lat,0,2);
  $latMinute=substr($lat,2,4);
  $latDD=$latDegrees+$latMinute/60;
  return $latDD;
}

function ConvDecimalMinutestoDecimalDdegrees_lng($lng) 
{
  $lngDegrees=substr($lng,0,3);
  $lngMinute=substr($lng,3,4);
  $lngDD=$lngDegrees+$lngMinute/60;
  return $lngDD;
}


$lat = $_GET['lat'];
$lat_dir = $_GET['lat_dir'];
$lng = $_GET['lng'];
$lng_dir = $_GET['lng_dir'];

$lat=ConvDecimalMinutestoDecimalDdegrees_lat($lat);
if($lat_dir == 'S')
	$lat=$lat*(-1);

$lng=ConvDecimalMinutestoDecimalDdegrees_lng($lng);
if($lng_dir == 'W')
	$lng=$lng*(-1);
	
echo $lat;
echo "<br>";
echo $lng;


$sql = "INSERT INTO tbl_gps(lat,lng,date) 
	VALUES('".$lat."','".$lng."','".date("Y-m-d H:i:s")."')";

if($db->query($sql) === FALSE)
	{ echo "Error: " . $sql . "<br>" . $db->error; }

echo "<br>";
echo $db->insert_id;
